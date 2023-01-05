// Matthew Bianchi card.h for euchre card game
// Card structure with helper functions
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Card
{
    int value;
    int suit;

    // Prints card with value and suit combination
    void printCard()
    {
        cout << "|";
        printValue();
        cout << " ";
        printSuit();
        cout << "|";
    }

    // Prints values of cards
    void printValue()
    {
        if (value == 10)
        {
            cout << "T";
        }
        else if (value == 11)
        {
            cout << "J";
        }
        else if (value == 12)
        {
            cout << "Q";
        }
        else if (value == 13)
        {
            cout << "K";
        }
        else if (value == 14)
        {
            cout << "A";
        }
        else
        {
            cout << value;
        }
    }

    // Prints suit of card
    void printSuit()
    {
        if (suit == 0)
        {
            cout << "H";
        }
        else if (suit == 1)
        {
            cout << "D";
        }
        else if (suit == 2)
        {
            cout << "S";
        }
        else if (suit == 3)
        {
            cout << "C";
        }
    }

    // Sets card ranking based on trump card for round and leadSuit for trick
    int cardRanking(int trump, int leadSuit)
    {
        int ranking;
        if (leadSuit == 0)
        {
            if (suit == 0 && value == 14)
            {
                ranking = 6;
            }
            else if (suit == 0 && value == 13)
            {
                ranking = 5;
            }
            else if (suit == 0 && value == 12)
            {
                ranking = 4;
            }
            else if (suit == 0 && value == 11)
            {
                ranking = 3;
            }
            else if (suit == 0 && value == 10)
            {
                ranking = 2;
            }
            else if (suit == 0 && value == 9)
            {
                ranking = 1;
            }
            else
            {
                ranking = 0;
            }
        }
        if (leadSuit == 1)
        {
            if (suit == 1 && value == 14)
            {
                ranking = 6;
            }
            else if (suit == 1 && value == 13)
            {
                ranking = 5;
            }
            else if (suit == 1 && value == 12)
            {
                ranking = 4;
            }
            else if (suit == 1 && value == 11)
            {
                ranking = 3;
            }
            else if (suit == 1 && value == 10)
            {
                ranking = 2;
            }
            else if (suit == 1 && value == 9)
            {
                ranking = 1;
            }
            else
            {
                ranking = 0;
            }
        }
        if (leadSuit == 2)
        {
            if (suit == 2 && value == 14)
            {
                ranking = 6;
            }
            else if (suit == 2 && value == 13)
            {
                ranking = 5;
            }
            else if (suit == 2 && value == 12)
            {
                ranking = 4;
            }
            else if (suit == 2 && value == 11)
            {
                ranking = 3;
            }
            else if (suit == 2 && value == 10)
            {
                ranking = 2;
            }
            else if (suit == 2 && value == 9)
            {
                ranking = 1;
            }
            else
            {
                ranking = 0;
            }
        }
        if (leadSuit == 3)
        {
            if (suit == 3 && value == 14)
            {
                ranking = 6;
            }
            else if (suit == 2 && value == 13)
            {
                ranking = 5;
            }
            else if (suit == 3 && value == 12)
            {
                ranking = 4;
            }
            else if (suit == 3 && value == 11)
            {
                ranking = 3;
            }
            else if (suit == 3 && value == 10)
            {
                ranking = 2;
            }
            else if (suit == 3 && value == 9)
            {
                ranking = 1;
            }
            else
            {
                ranking = 0;
            }
        }
        if (trump == 0)
        {
            if (suit == 0 && value == 11)
            {
                ranking = 13;
            }
            else if (suit == 1 && value == 11)
            {
                ranking = 12;
            }
            else if (suit == 0 && value == 14)
            {
                ranking = 11;
            }
            else if (suit == 0 && value == 13)
            {
                ranking = 10;
            }
            else if (suit == 0 && value == 12)
            {
                ranking = 9;
            }
            else if (suit == 0 && value == 10)
            {
                ranking = 8;
            }
            else if (suit == 0 && value == 9)
            {
                ranking = 7;
            }
        }
        if (trump == 1)
        {
            if (suit == 1 && value == 11)
            {
                ranking = 13;
            }
            else if (suit == 0 && value == 11)
            {
                ranking = 12;
            }
            else if (suit == 1 && value == 14)
            {
                ranking = 11;
            }
            else if (suit == 1 && value == 13)
            {
                ranking = 10;
            }
            else if (suit == 1 && value == 12)
            {
                ranking = 9;
            }
            else if (suit == 1 && value == 10)
            {
                ranking = 8;
            }
            else if (suit == 1 && value == 9)
            {
                ranking = 7;
            }
        }
        else if (trump == 2)
        {
            if (suit == 2 && value == 11)
            {
                ranking = 13;
            }
            else if (suit == 3 && value == 11)
            {
                ranking = 12;
            }
            else if (suit == 2 && value == 14)
            {
                ranking = 11;
            }
            else if (suit == 2 && value == 13)
            {
                ranking = 10;
            }
            else if (suit == 2 && value == 12)
            {
                ranking = 9;
            }
            else if (suit == 2 && value == 10)
            {
                ranking = 8;
            }
            else if (suit == 2 && value == 9)
            {
                ranking = 7;
            }
        }
        else if (trump == 3)
        {
            if (suit == 3 && value == 11)
            {
                ranking = 13;
            }
            else if (suit == 2 && value == 11)
            {
                ranking = 12;
            }
            else if (suit == 3 && value == 14)
            {
                ranking = 11;
            }
            else if (suit == 3 && value == 13)
            {
                ranking = 10;
            }
            else if (suit == 3 && value == 12)
            {
                ranking = 9;
            }
            else if (suit == 3 && value == 10)
            {
                ranking = 8;
            }
            else if (suit == 3 && value == 9)
            {
                ranking = 7;
            }
        }

        return ranking;
    }
};