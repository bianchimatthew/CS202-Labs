// Lab 10: kth Smallest Number Lab
// Matthew Bianchi COSC202
// Creates percolateDown function and pop function to find the kth smallest term in a minHeap Binary Tree

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//percolateDown that builds maxHeap
void maxDown(vector <int> &maxHeap, int n, int i){
  int parent = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
 
  //If left child is greater than parent sets left child to new parent
  if (left < n && maxHeap[left] > maxHeap[parent]){
    parent = left;
  }

  //If right child is greater than parent sets left child to new parent
  if (right < n && maxHeap[right] > maxHeap[parent]){
    parent = right;
  }

  //Swaps parent and child and recursively calls maxDown for the new sub trees
  if (parent != i) {
    swap(maxHeap[i], maxHeap[parent]);
    maxDown(maxHeap, n, parent);
  }
}

//percolateDown that builds minHeap
void percolateDown(vector <int> &heap, int n, int i)
{
    int parent = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    //If left child is less than parent sets left child to new parent
    if (left < n && heap[left] < heap[parent]){
      parent = left;
    }

    //If right child is less than parent sets left child to new parent
    if (right < n && heap[right] < heap[parent]){
      parent = right;
    }

    //Swaps parent and child and recursively calls percolateDown for the new sub trees
    if (parent != i) {
      swap(heap[i], heap[parent]);
      percolateDown(heap, n, parent);
    }
}

//sends first root node to the end of the array and pops the next node to the root
void pop(vector <int> &heap, int n){
  heap[0] = heap.back();
  heap.pop_back();

  percolateDown(heap, n, 0);
}

int main(int argc, char *argv[])
{
  vector <int> v;
  vector <int> minHeap;
  int val;
  int N;
  int K;

  //Keeps reading input from input file
  while (cin >> N) {
    cin >> K;
    for (int i = 0; i < N; i++) {
      cin >> val;
      v.push_back(val);
    }

  minHeap = v;

  //Creates minHeap Binary Tree using percolateDown function for finding kth smallest term
  for (int i = N / 2 - 1; i >= 0; i--){
        percolateDown(minHeap, N, i);
  }

  vector <int> maxHeap;
  maxHeap = v;

  //Creates maxHeap Binary tree for finding if the given array is a maxHeap
  for (int i = N / 2 - 1; i >= 0; i--){
        maxDown(maxHeap, N, i);
  }  

  //Checks if the maxHeap array is equal to the given array if it is then the array is a maxHeap.
  if (std::equal(maxHeap.begin(), maxHeap.begin() + N, v.begin())){
    printf("Y  ");
  } else {
    printf("N  ");
  }

  //Pops top node off the minHeap binary tree k-1 amount of times
  for(int i = 0; i < K-1; i++){
    pop(minHeap, N);
  }

  //Prints new head of minHeap that is the kth smallest term
  printf("%d\n", minHeap[0]);
    minHeap.clear();
    v.clear();
    maxHeap.clear();
  }
  
  return 0;

}
