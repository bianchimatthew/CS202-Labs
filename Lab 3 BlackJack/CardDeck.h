//Matthew Bianchi Lab3 COSC 202
//BlackJack CardDeck class header file

#ifndef CARDDECK_H
#define CARDDECK_H

#include <iostream>


class CardDeck {
    private: 
        int *deck; //Deck Pointer
        int size;
    public:
        //Default and Copy Constructor, Destructor, Assignment Operator and size of the array Functions
        CardDeck(int n = 52);
        CardDeck(const CardDeck &obj);
        ~CardDeck();
        const CardDeck &operator = (const CardDeck &obj);
        int getSize();

        //Game Functions
        void shuffle();
        void display();
        void deal(int *&hand, int *handSize);
        int handValue(int *&hand, int *handSize);
        void displayHand(int *&hand, int *handSize);   
}; //End CardDeck Class

#endif
