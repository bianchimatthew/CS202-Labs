
//Matthew Bianchi Lab3 COSC 202
//Black Jack Game with Constructors and Pointers

#include "CardDeck.h"
using namespace std;

int main() {
  CardDeck * deck; //Pointer to CardDeck Object

  //Test Deck Case
  deck = new CardDeck(10);
  deck->display();
  deck->shuffle();
  deck->display();
  delete deck;
  printf("\n");

  //Beginning of Black Jack Game
  deck = new CardDeck();
  deck->shuffle();

  //Keeps track of scoreboard
  int playerWin = 0;
  int dealerWin = 0;
  int tie = 0;
  
  //Keeps track of number of cards in player and dealer's hand
  int playerHandCount;
  int dealerHandCount;

  char choice;

  do{
    //Deletes current deck and shuffles new deck whenever the deckSize gets below 15 cards
    if(deck->getSize() < 15){
      delete deck;
      deck = new CardDeck();
      for(int i = 0; i < (rand() % 10) + 1; i++){
        deck -> shuffle();
      }
    }

    //Scoreboard
    printf("---------------------------------\n");
    printf("player [%d] | dealer [%d] | tie [%d]\n", playerWin, dealerWin, tie);
    
    //Uses a pointer to create the player and dealer's hand arrays
    int *player = new int[0];
    int *dealer = new int[0];

    //resets hand count to zero after each round
    playerHandCount = 0;
    dealerHandCount = 0;

    //Draws first two cards for player and dealer.
    deck->deal(*&player, &playerHandCount);
    deck->deal(*&dealer, &dealerHandCount);
    deck->deal(*&player, &playerHandCount);
    deck->deal(*&dealer, &dealerHandCount);

    //Displays Player's starting hand
    printf("Player's Hand: ");
    deck->displayHand(*&player, &playerHandCount);
    printf("Valuing %d\n", deck->handValue(*&player, &playerHandCount));

    //Displays Dealer's Starting Hand with the first card unkown
    printf("Dealer's Hand: [?] ");
    if(dealer[1] == 13){
        printf("[K] ");
      } else if(dealer[1] == 12){
          printf("[Q] ");
      } else if(dealer[1] == 11){
          printf("[J] ");
      } else if(dealer[1] == 1){
          printf("[A] ");
      } else {
            printf("[%d] ", dealer[1]);
    }
    printf("\n");
    
    //Players Turn
    while(true){
      printf("Would you like to (h)it or (s)tand? ");
      cin >> choice;

      //Hit
      if(choice == 'h'){
        //Deals a single card whenever player hits
        deck->deal(*&player, &playerHandCount);
  
        //Displays players current hand
        printf("\nPlayer hits\n\nPlayer's Hand: ");
        deck->displayHand(*&player, &playerHandCount);
        
        //Calculates value of player's hand
        printf("\nPlayer's Hand Totals: %d\n", deck->handValue(*&player, &playerHandCount));

        //Player Busts
        if(deck->handValue(*&player, &playerHandCount) > 21){
          printf("\nYou Bust\n");
          dealerWin++;
          break;
        }
      
      //Stand
      } else if(choice == 's'){
        printf("\nPlayer Stands\n\n");
        break;
      }
    }
    
    //Dealers Turn
    //Loop only runs if player's hand is not over 21
    if(deck->handValue(*&player, &playerHandCount) <= 21){
      while(true){
        //Displays dealer's current hand
        printf("Dealer's Hand: ");
        deck->displayHand(*&dealer, &dealerHandCount);

        //Calculates value of dealer's hand
        printf("\nDealer's Hand Totals: %d\n", deck->handValue(*&dealer, &dealerHandCount));

        //Dealer Busts
        if(deck->handValue(*&dealer, &dealerHandCount) > 21){
          printf("\nDealer Busts\n");
          playerWin++;
          break;

        //Dealer Stands
        } else if(deck->handValue(*&dealer, &dealerHandCount) >= 17){
          printf("\nDealer Stands\n\n");
          break;

        //Dealer Hits  
        } else if (deck->handValue(*&dealer, &dealerHandCount) < 17){
          printf("\nDealer Hits\n\n");
          deck->deal(*&dealer, &dealerHandCount);
    
        }
      }
    }
    
    //Finds who won if no one busts
    if(deck->handValue(*&player, &playerHandCount) > deck->handValue(*&dealer, &dealerHandCount) && deck->handValue(*&player, &playerHandCount) <= 21){
      printf("Player Wins!\n");
      playerWin++;
    } else if(deck->handValue(*&player, &playerHandCount) < deck->handValue(*&dealer, &dealerHandCount) && deck->handValue(*&dealer, &dealerHandCount) <= 21) {
      printf("Dealer Wins!\n");
      dealerWin++;
    } else if(deck->handValue(*&player, &playerHandCount) == deck->handValue(*&dealer, &dealerHandCount)){
      printf("Push!\n");
      tie++;
    }

    //Deletes player and dealer's current hands from memory.
    delete[] player;
    delete[] dealer;

    //Choice to continue game or not
    printf("Do you wish to continue? (y/n) ");
    cin >> choice;
    if(choice == 'y'){
      continue;
    } else {
      break;
    } 
  } while(true);
  
  printf("-----------Final--Score----------\n");
  printf("player [%d] | dealer [%d] | tie [%d]\n", playerWin, dealerWin, tie);

  //Frees memory taken up by deck by use of deconstructor
  delete deck;
  return 0;
}
