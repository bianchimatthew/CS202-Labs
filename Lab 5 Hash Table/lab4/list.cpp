#include "list.h"
#include <string>
using namespace std;

//start of Node functions

//Node Constructor
Node::Node(int i) {
	data = i;
	next = NULL;
}
//end of Node functions

//Start of List Functions

//List Constructor
List::List() {
	head = NULL;
	count = 0;
}

//copied Dr. Emrich's function
List::~List() {
	if (!empty()) { // follow the links, clobbering as we go
		Node *p = head;

		while (p != NULL) {
			Node *next = p->next; // retrieve this node's "next" before we clobber it
			delete p;
			p = next;
		}
	}
}

//helper function to create a new node
Node *List::newNode(int i) {
	Node *node = new Node(i);
	node->next = NULL;
	return node;
}

//copied Dr. Emrich's function
//Adds new node to end of list
void List::addNode(int i) {
    Node *nextNode = newNode(i);
	if(empty()){
        head = nextNode;
    } else {
        Node *pointer = head;
        while(pointer->next != NULL){
            pointer = pointer->next;
        }
        pointer->next = nextNode;
    }
	count++;
    return;
}

//Checks if List is empty
bool List::empty() {
	if(head == NULL){
        return true;
    } else {
        return false;
    }
}

//Gets memory value for head of list
Node *List::getHead() {
	return head;
}

//Reverses linked list
void List::reverse(){
	Node *pointer = NULL;
    Node *prev = NULL;
    Node *current = head;
    while(current != NULL) {
        pointer = current->next;
        current->next = prev;
        prev = current;
        current = pointer;
    }
    head = prev;
}

//Prints Linked List
void List::print() {
	if (!empty()) { // follow the links, printing as we go
		Node *pointer = head;
        while(pointer != NULL){
            printf("%d", pointer->data);
			pointer = pointer->next;
        }
	} else {
		printf("empty\n");
	}
}
//end of List functions
