// Lab 04: Adding List-Based Integers
// Matthew Bianchi
// Creates two custom linked lists with fundamental type int 
// and adds the values together to create one sum linked list
#include "list.h"
#include <cstdio>
#include <iostream>

using namespace std;

//Helper function to add two linked lists
List *sumLists(List *list1, List *list2) {

    //Creates sum of lists
    List * sumList;
    sumList = new List;

    int sum = 0;
    int carry = 0;

    //Creates pointer to head of linked list
    Node *pointer1 = list1->getHead();
    Node *pointer2 = list2->getHead();

    //Loops through each node the two lists
    while(pointer1 != NULL || pointer2 != NULL || sum > 0){

        //Adds data from l1 to the sum and moves to the next node
        if(pointer1 != NULL){
            sum += pointer1->data;
            pointer1 = pointer1->next;
        }

        //Adds data from l2 to the sum and moves to the next node
        if(pointer2 != NULL){
            sum += pointer2->data;
            pointer2 = pointer2->next;
        }
        //Calculates carry to the sum and adds sum to linked list
        carry = sum / 10;
        sum = sum % 10;
        sumList->addNode(sum);

        //carry is carried onto the sum for the next iteration
        sum = carry;
        carry = 0;
    }
    return sumList;
}

int main(int argc, char *argv[]) {

    string c;
    int listCount = 0;

    //Creates list Objects
    List * linkedList1;
    List * linkedList2;
    List * sumList;

    //Creates new L1 and L2
    linkedList1 = new List;
    linkedList2 = new List;

    //Runs as long as there is input from the file
    while(cin >> c){
        //Creates new lists after previous lists were added together
        if(listCount > 0 && listCount % 2 == 0){
            delete linkedList1;
            delete linkedList2;
            delete sumList;
            linkedList1 = new List;
            linkedList2 = new List;
        }
        //Adds value to L1 Node
        if(listCount % 2 == 0){
            for(int i = c.length()-1; i >= 0; i--){
                linkedList1->addNode(c[i]-48);
            }
            listCount++;
        //Adds value to L2 Node
        } else {
            for(int i = c.length()-1; i >= 0; i--){
                linkedList2->addNode(c[i]-48);
            }
            listCount++;
            //Initializes sumList to the return value of SumLists() function, reverses and prints
            sumList = sumLists(linkedList1, linkedList2);
            sumList->reverse();
            sumList->print();

            
            printf("\n");
        }
    }

    delete sumList;
    delete linkedList1;
    delete linkedList2;

	return 0;
}
