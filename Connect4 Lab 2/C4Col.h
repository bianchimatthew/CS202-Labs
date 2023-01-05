//Matthew Bianchi
//Column class header file
#include <iostream>

class C4Col {
    private: 
        int numDiscs;
        int maxDiscs;
        char discs[6]; //Change the array value to alter the column size
	public:
        C4Col();
        int isFull();
        char getDisc(int);
        int getMaxDiscs();
        void addDisc(char);
};


