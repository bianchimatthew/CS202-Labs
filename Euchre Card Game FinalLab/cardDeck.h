// Matthew Bianchi cardDeck.h for euchre card game
// Card deck structure with helper functions
#include "card.h"


struct Deck
{

    // starting deck and shuffled Deck vector initialization
    vector<Card> startDeck;
    vector<Card> shuffledDeck;

    // Prints hand of player
    void printHand(vector<Card> deck)
    {
        for (long unsigned int i = 0; i < deck.size(); i++)
        {
            deck.at(i).printCard();
        }
    }

    // Creates cards with proper suit value combination and appends them to starting deck vector
    void deckSetup()
    {
        for (int i = 0; i <= 3; i++)
        {
            for (int j = 9; j <= 14; j++)
            {
                Card c;
                c.suit = i;
                c.value = j;
                startDeck.push_back(c);
            }
        }
    }

    // Prints ordered Deck for testing
    void printStartDeck()
    {
        for (long unsigned int i = 0; i < startDeck.size(); i++)
        {
            startDeck.at(i).printCard();
        }
    }

    // Prints shuffled deck for testing
    void printShuffledDeck()
    {
        for (long unsigned int i = 0; i < shuffledDeck.size(); i++)
        {
            shuffledDeck.at(i).printCard();
        }
    }

    // Fisher-Yates Shuffle Algorithm for shuffling sorted deck
    void shuffleDeck()
    {
        while (startDeck.size() > 0)
        {
            int x = rand() % (startDeck.size());
            shuffledDeck.push_back(startDeck.at(x));
            startDeck.erase(startDeck.begin() + x);
        }
    }

    // Clears remainding 4 cards from the shuffled deck
    void clearDeck()
    {
        while (shuffledDeck.size() > 0)
        {
            shuffledDeck.erase(shuffledDeck.begin());
        }
    }

    // Draws card from shuffled deck adds it to player hand and removes it from the shuffled deck
    void drawCard(vector<Card> *hand)
    {
        hand->push_back(shuffledDeck.at(0));
        shuffledDeck.erase(shuffledDeck.begin());
    }

    // Removes card from hand after it is played
    void removeCard(vector<Card> *hand, int num)
    {
        hand->erase(hand->begin() + num);
    }

    // Sets trump card based on the top card in the remainding non dealt cards for simplicity
    int setTrump()
    {
        int trump = shuffledDeck.at(0).suit;
        cout << "----------Trump----------" << endl
             << "          ";
        shuffledDeck.at(0).printCard();
        cout << endl;
        return trump;
    }
};