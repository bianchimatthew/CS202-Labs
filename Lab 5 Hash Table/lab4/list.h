#include <cstdio>

#ifndef LIST_H
#define LIST_H

//start of Node class
class Node {
	public:
		Node(int);
		int data;
		Node *next;
};
//end of Node class

//start of List class
class List {
	private:
		Node *head;
		Node *newNode(int);
		int count;
	public:
		List();
		~List();
		void addNode(int i);
		bool empty();
		Node *getHead();
		void print();
		void reverse();
		
};
//end of List class
#endif
