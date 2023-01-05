//Matthew Bianchi Lab3 COSC 202
//BlackJack CardDeck constructors and game functions

#include "CardDeck.h"
#include <algorithm>

//Default Constructor
CardDeck::CardDeck(int n){
    size = n;
    deck = new int[size];
    for(int i = 0; i < size; i++){
        deck[i] = (i % 13) + 1;
    }   
    return;
} 

//Copy Constructor From Dr. Scott's Rule of Three
CardDeck::CardDeck(const CardDeck &obj) : size(obj.size){
    deck = new int[size]; // create space for pointer-based array

    for ( int i = 0; i < size; i++ ){
        deck[i] = obj.deck[i]; // copy into object
    }

}

//Destructor
CardDeck::~CardDeck(){
    delete[] deck;
}

//Assignment Operator
const CardDeck &CardDeck::operator = (const CardDeck &obj){
    if(&obj != this){
        if(size != obj.size){
            delete[] deck;
            size = obj.size;
            deck = new int[size];
        }

        for(int i = 0; i < size; i++){
            deck[i] = obj.deck[i];
        }
    }
    return *this;
}

//Gets Size of Deck
int CardDeck::getSize(){
    return size;
}

//Shuffles Deck
void CardDeck::shuffle(){
    std::random_shuffle(&deck[0], &deck[size]);
    return;
}

//Displays Deck
void CardDeck::display(){
    for(int i = 0; i < getSize(); i++){
        printf("%d ", deck[i]);
    }
    printf("\n");
    return;
}

//Deals card to hand
void CardDeck::deal(int *&hand, int *handSize){
    int *new_hand = new int[*handSize + 1];
    for(int i = 0; i < *handSize; i++){
        new_hand[i] = hand[i];
    }
    delete[] hand;

    new_hand[*handSize] = *deck;
    size--;
    hand = new_hand;

    for(int i = 0; i < size; i++){
        deck[i] = deck[i + 1];
    }

    //When new card is added increases handSize by 1
    *handSize += 1;
    return;
}

//Calculates the total of the hand
int CardDeck::handValue(int *&hand, int *handSize){
    int handTotal = 0;
    for(int i = 0; i < *handSize; i++){
        if(hand[i] > 9){
          handTotal += 10;
        } else if(hand[i] == 1) {
           handTotal += 11;
        } else {
          handTotal += hand[i];
        }
      }
      return handTotal;
}

//Displays Hand with K for 13 Q for 12 J for 11 and A for 1
void CardDeck::displayHand(int *&hand, int *handSize){ 
    for(int i = 0; i < *handSize; i++){
        if(hand[i] == 13){
            printf("[K] ");
        } else if(hand[i] == 12){
            printf("[Q] ");
        } else if(hand[i] == 11){
            printf("[J] ");
        } else if(hand[i] == 1){
            printf("[A] ");
        } else {
            printf("[%d] ", hand[i]);
        }
    }
    return;
}