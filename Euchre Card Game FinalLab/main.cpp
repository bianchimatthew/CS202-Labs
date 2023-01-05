// Matthew Bianchi Final Lab: Euchre
// Simulates game of Euchre
#include "cardDeck.h"


int main()
{
    // Deck struct
    Deck deck;

    int playerTeamScore = 0;
    int CPUTeamScore = 0;
    int turnCount = 0;

    //Game loop
    while (true)
    {
        // If either of the teams score ever reaches 5 loop breaks and game is over
        if (playerTeamScore == 5 || CPUTeamScore == 5)
        {
            break;
        }
        deck.deckSetup();
        // deck.printStartDeck();
        // cout << endl;
        deck.shuffleDeck();
        // deck.printShuffledDeck();
        // cout << endl;

        // Initializes player and computer hand vectors for during rounds
        vector<Card> playerHand;
        vector<Card> c1Hand;
        vector<Card> c2Hand;
        vector<Card> c3Hand;

        int trump = 0;

        // Draws 5 cards for each player with rotating who is dealt first
        for (int i = 0; i < 5; i++)
        {
            if (turnCount % 4 == 0)
            {
                deck.drawCard(&playerHand);
                deck.drawCard(&c1Hand);
                deck.drawCard(&c2Hand);
                deck.drawCard(&c3Hand);
            }
            if (turnCount % 4 == 1)
            {
                deck.drawCard(&c1Hand);
                deck.drawCard(&c2Hand);
                deck.drawCard(&c3Hand);
                deck.drawCard(&playerHand);
            }
            if (turnCount % 4 == 2)
            {
                deck.drawCard(&c2Hand);
                deck.drawCard(&c3Hand);
                deck.drawCard(&playerHand);
                deck.drawCard(&c1Hand);
            }
            if (turnCount % 4 == 3)
            {
                deck.drawCard(&c3Hand);
                deck.drawCard(&playerHand);
                deck.drawCard(&c1Hand);
                deck.drawCard(&c2Hand);
            }
        }

        // Initalizes all players trick scores during the round and resets to zero after round is over
        int playerTrickScore = 0;
        int cpu1TrickScore = 0;
        int cpu2TrickScore = 0;
        int cpu3TrickScore = 0;

        // ScoreBoard
        cout << "----------Score----------" << endl;
        cout << "          " << playerTeamScore << " - " << CPUTeamScore << endl;
        while (playerHand.size() > 0)
        {
            // Start of Round

            long unsigned int playerChoice;
            // CPU make initial random choice from their hand based on the size of their hand
            int CPU1Choice = rand() % c1Hand.size();
            int CPU2Choice = rand() % c2Hand.size();
            int CPU3Choice = rand() % c3Hand.size();

            // Keeps count of turns in trick
            int trickCount = 0;
            // Holds leadingSuit
            int leadSuit;

            bool suitInHand = false;
            trump = deck.setTrump();
            cout << "----------Trick----------" << endl;
            // Trick Turn Loop
            while (trickCount < 4)
            { // Player Turn
                if (turnCount % 4 == 0)
                {      
                    deck.printHand(playerHand);
                    cout << endl;
                    cout << "Choose a card to place (1-";
                    cout << playerHand.size() << "): ";
                    cin >> playerChoice;
                    //If player is not the first to play the trick checks if the they have a suit matching the lead suit in hand
                    if(trickCount > 0){
                        for(long unsigned int i = 0; i < playerHand.size(); i++){
                            if(playerHand.at(i).suit == leadSuit){
                                suitInHand = true;
                            }
                        }
                        //If they do have a lead suit in hand player must play it
                        if (suitInHand == true)
                        {   
                            while ((playerChoice < 1 || playerChoice > playerHand.size()) || (playerHand.at(playerChoice - 1).suit != leadSuit))
                            {
                                cout << "Invalid Card - Choose a ";
                                if (leadSuit == 0)
                                {
                                    cout << "Hearts: ";
                                }
                                else if (leadSuit == 1)
                                {
                                    cout << "Diamonds: ";
                                }
                                else if (leadSuit == 2)
                                {
                                    cout << "Spades: ";
                                }
                                else if (leadSuit == 3)
                                {
                                    cout << "Clubs: ";
                                }
                                cin.clear();
                                cin.ignore();
                                cin >> playerChoice;
                            }
                        }
                    }
                    //Input Error Checking
                    while (playerChoice < 1 || playerChoice > playerHand.size())
                    {
                        cout << "Invalid Card - Choose a card to place (1-";
                        cout << playerHand.size() << "): ";
                        cin.clear();
                        cin.ignore();
                        cin >> playerChoice;
                    }

                    // If card is the first card in the trick the suit of that card becomes the leading suit
                    if (trickCount == 0)
                    {
                        leadSuit = playerHand.at(playerChoice - 1).suit;
                    }
                    cout << "Player 1: ";
                    playerHand.at(playerChoice - 1).printCard();
                    //If uncommented shows the ranking next to each card
                    // cout << " " << playerHand.at(playerChoice - 1).cardRanking(trump, leadSuit);
                    cout << " " << playerTrickScore << endl;
                    trickCount++;
                    turnCount++;
                }
                // CPU1 Turn
                if (turnCount % 4 == 1 && trickCount < 4)
                {
                    // If the CPU plays the first card in trick the suit of their placed card becomes the leading suit
                    if (trickCount == 0)
                    {
                        leadSuit = c1Hand.at(CPU1Choice).suit;
                    }
                    else
                    {
                        // If CPU has a card in hand that is the same suit as the leadingSuit they have to play it
                        for (long unsigned int i = 0; i < c1Hand.size(); i++)
                        {
                            if (c1Hand.at(i).suit == leadSuit)
                            {
                                CPU1Choice = i;
                            }
                        }
                    }
                    cout << "   CPU 1: ";
                    c1Hand.at(CPU1Choice).printCard();
                    //If uncommented shows the ranking next to each card
                    // cout << " " << c1Hand.at(CPU1Choice).cardRanking(trump, leadSuit) << endl;
                    cout << " " << cpu1TrickScore << endl;
                    trickCount++;
                    turnCount++;
                }
                // CPU2 Turn
                if (turnCount % 4 == 2 && trickCount < 4)
                {
                    // If the CPU plays the first card in trick the suit of their placed card becomes the leading suit
                    if (trickCount == 0)
                    {
                        leadSuit = c2Hand.at(CPU2Choice).suit;
                    }
                    else
                    {
                        // If CPU has a card in hand that is the same suit as the leadingSuit they have to play it
                        for (long unsigned int i = 0; i < c2Hand.size(); i++)
                        {
                            if (c2Hand.at(i).suit == leadSuit)
                            {
                                CPU2Choice = i;
                            }
                        }
                    }
                    cout << "   CPU 2: ";
                    c2Hand.at(CPU2Choice).printCard();
                    //If uncommented shows the ranking next to each card
                    // cout << " " << c2Hand.at(CPU2Choice).cardRanking(trump, leadSuit) << endl;
                    cout << " " << cpu2TrickScore << endl;
                    trickCount++;
                    turnCount++;
                }
                // CPU3 Turn
                if (turnCount % 4 == 3 && trickCount < 4)
                {
                    // If the CPU plays the first card in trick the suit of their placed card becomes the leading suit
                    if (trickCount == 0)
                    {
                        leadSuit = c3Hand.at(CPU3Choice).suit;
                    }
                    else
                    {
                        // If CPU has a card in hand that is the same suit as the leadingSuit they have to play it
                        for (long unsigned int i = 0; i < c3Hand.size(); i++)
                        {
                            if (c3Hand.at(i).suit == leadSuit)
                            {
                                CPU3Choice = i;
                            }
                        }
                    }
                    cout << "   CPU 3: ";
                    c3Hand.at(CPU3Choice).printCard();
                    //If uncommented shows the ranking next to each card
                    // cout << " " << c3Hand.at(CPU3Choice).cardRanking(trump, leadSuit) << endl;
                    cout << " " << cpu3TrickScore << endl;
                    trickCount++;
                    turnCount++;
                }
            }

            // Trick win checker
            if (playerHand.at(playerChoice - 1).cardRanking(trump, leadSuit) > c1Hand.at(CPU1Choice).cardRanking(trump, leadSuit) && playerHand.at(playerChoice - 1).cardRanking(trump, leadSuit) > c2Hand.at(CPU2Choice).cardRanking(trump, leadSuit) && playerHand.at(playerChoice - 1).cardRanking(trump, leadSuit) > c3Hand.at(CPU3Choice).cardRanking(trump, leadSuit))
            {
                cout << "You win the trick" << endl;
                playerTrickScore++;
            }
            else if (c1Hand.at(CPU1Choice).cardRanking(trump, leadSuit) > playerHand.at(playerChoice - 1).cardRanking(trump, leadSuit) && c1Hand.at(CPU1Choice).cardRanking(trump, leadSuit) > c2Hand.at(CPU2Choice).cardRanking(trump, leadSuit) && c1Hand.at(CPU1Choice).cardRanking(trump, leadSuit) > c3Hand.at(CPU3Choice).cardRanking(trump, leadSuit))
            {
                cout << "CPU1 wins the trick" << endl;
                cpu1TrickScore++;
            }
            else if (c2Hand.at(CPU2Choice).cardRanking(trump, leadSuit) > playerHand.at(playerChoice - 1).cardRanking(trump, leadSuit) && c2Hand.at(CPU2Choice).cardRanking(trump, leadSuit) > c1Hand.at(CPU1Choice).cardRanking(trump, leadSuit) && c2Hand.at(CPU2Choice).cardRanking(trump, leadSuit) > c3Hand.at(CPU3Choice).cardRanking(trump, leadSuit))
            {
                cout << "CPU2 wins the trick" << endl;
                cpu2TrickScore++;
            }
            else if (c3Hand.at(CPU3Choice).cardRanking(trump, leadSuit) > playerHand.at(playerChoice - 1).cardRanking(trump, leadSuit) && c3Hand.at(CPU3Choice).cardRanking(trump, leadSuit) > c1Hand.at(CPU1Choice).cardRanking(trump, leadSuit) && c3Hand.at(CPU3Choice).cardRanking(trump, leadSuit) > c2Hand.at(CPU2Choice).cardRanking(trump, leadSuit))
            {
                cout << "CPU3 wins the trick" << endl;
                cpu3TrickScore++;
            }
            cout << endl;

            // Removes cards from players hands
            deck.removeCard(&playerHand, playerChoice - 1);
            deck.removeCard(&c1Hand, CPU1Choice);
            deck.removeCard(&c2Hand, CPU2Choice);
            deck.removeCard(&c3Hand, CPU3Choice);

            // Increments to keep turns rotating
            turnCount++;

            // Once all 5 tricks are played adds score accordingly
            if ((playerTrickScore + cpu1TrickScore + cpu2TrickScore + cpu3TrickScore) == 5)
            {
                if ((cpu1TrickScore + cpu3TrickScore) == 5)
                {
                    CPUTeamScore += 2;
                }
                else if (cpu1TrickScore + cpu3TrickScore >= 3)
                {
                    CPUTeamScore++;
                }
                else if (playerTrickScore + cpu2TrickScore == 5)
                {
                    playerTeamScore += 2;
                }
                else if (playerTrickScore + cpu2TrickScore >= 3)
                {
                    playerTeamScore++;
                }
            }
        }
        // Clears remaining 4 cards left in deck before recreating deck and reshuffling
        deck.clearDeck();
    }
    // Prints final score and winning team
    cout << "-------Final-Score-------" << endl;
    cout << "          " << playerTeamScore << " - " << CPUTeamScore << endl;
    if (playerTeamScore == 5)
    {
        cout << "         You Win         " << endl;
    }
    else
    {
        cout << "         CPU Win         " << endl;
    }
}