// Lab 9:  Binary Tree Lab
// Matthew Bianchi COSC202
// Initializes different functions/helper functions to create a working binary tree that can find depth of a node, max height of a tree, as well as balance any given binary tree.

#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include "bstree.hpp"
using namespace std;
using CS140::BSTree;
using CS140::BSTNode;

//Finds depth of any given node in a tree
int BSTree::Depth(const string &key) const
{
  //Declares new node
	BSTNode *n;

  //Depth count
	int count = 0;

  //Initializes newly created node to the parent of the tree
	n = sentinel->right;

  //Loops as long as n is not equal to the sentinel node
  while (n != sentinel) {

    //When key is found returns count
    if (n->key == key) {
      return count;
    }
    //Checks to see if the key is less than or greater than the key at the node to know how to traverse the tree.
    if(key < n->key){
      count++;
      n = n->left;
    } else {
      count++;
      n = n->right;
    }
  }

  //If key not found returns -1
  return -1;
}

// Returns the depth of the node with maximum depth, plus one       
int BSTree::Height() const
{
	//use recursive helper function
	return recursive_find_height(sentinel->right) + 1;
}

// Return a vector of sorted keys
vector <string> BSTree::Ordered_Keys() const
{
  vector <string> rv;
  make_key_vector(sentinel->right, rv); //call helper function
  return rv;
}
   
//copy constructor
BSTree::BSTree(const BSTree &t)        
{
	//allocate new sentinel
	sentinel = new BSTNode;
	sentinel->left = NULL;
	sentinel->right = sentinel;
	sentinel->parent = NULL;
	sentinel->key = "---SENTINEL---";
	sentinel->val = NULL;
	
	size = 0; //reset size

	*this = t; //set object (uses assignment overload)
}

//assignment overload
BSTree& BSTree::operator= (const BSTree &t) 
{
	Clear(); //clear tree
	
	//create new balanced tree
	make_balanced_tree(t.Ordered_Keys(), t.Ordered_Vals(), 0, t.size);

	size = t.size; //set size

	return *this;
}

//recursive helper function to find greatest depth
int BSTree::recursive_find_height(const BSTNode *n) const
{
	if(n == sentinel){ //Base case
    return -1;
  } else { // Uses recursion to check tree and find max depth/height of the tree
    int lheight = recursive_find_height(n->left);
    int rheight = recursive_find_height(n->right);


    if(lheight > rheight){
      return (lheight + 1);
    } else {
      return (rheight + 1);
    }
  }
}

//recursive helper function to create ordered key vector
void BSTree::make_key_vector(const BSTNode *n, vector<string> &v) const
{
  //Uses recursion to order key vector
	if(n != sentinel){ //Base case
    make_key_vector(n->left, v);
    v.push_back(n->key);
    make_key_vector(n->right, v);
  }
}

//recursive helper function to create balanced tree in assignment overload.
//post-order traversal (children traversed before parents)
BSTNode *BSTree::make_balanced_tree(const vector<string> &sorted_keys, const vector<void *> &vals,size_t first_index,size_t num_indices) const
{
  //Declares new nodes for left and right child
  BSTNode *leftChild;
  BSTNode *rightChild;

  //Initializes left and right child to sentinel
  leftChild = sentinel;
  rightChild = sentinel;

  //Calculates middle of array
  int mid = first_index + (num_indices/2);


  //Uses recursion to order the left and right child as needed
  if(num_indices > 1){ // Base case
    if(num_indices % 2 == 0){ //Even Range
      leftChild = make_balanced_tree(sorted_keys, vals, first_index, (num_indices/2));
      if(((num_indices/2) - 1) > 0){
        rightChild = make_balanced_tree(sorted_keys, vals, mid + 1, ((num_indices/2) - 1));
      }
    } else { //Odd Range
      leftChild = make_balanced_tree(sorted_keys, vals, first_index, (num_indices/2));
      rightChild = make_balanced_tree(sorted_keys, vals, mid + 1, (num_indices/2));
    }
  }

  //Initializes new root node in order to form tree.
  BSTNode *i = new BSTNode;
  
  //Sets parent of left and right child to i
  leftChild->parent = i;
  rightChild->parent = i;

  //Sets left and right child to corresponding left and right child found using recursion
  i->left = leftChild;
  i->right = rightChild;

  //Sets parent of root node to sentinel
  i->parent = sentinel;

  //Sets key and val at i node
  i->key = sorted_keys.at(mid);
  i->val = vals.at(mid);

  //if first loop through sets right child of sentinel equal to i
  if(num_indices == sorted_keys.size()){
    sentinel->right = i;
  }

  //Returns new root node to assignment overload 
	return i;
}
