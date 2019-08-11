// Q. Bubble sort
// Algo:
// Assume that first element is the biggest element in the vector
// Traverse the vector(from 0 to n) and copmare every consecutive pair of elements
// if the value of the element at the lower index is bigger than the value of the element at the higher index, swap them
// do this for one complete traversal of the vector, it would bring the largest element at the last index and hence that index is sorted
// if we have n elements then we have to sort for the remaining n - 1 elements, as last element is now already sorted
// we would at most need to run the loop n - 1 more times to sort every element in the worst case scenario
// therefore we would need to run two nested for loops to execute the above algorithm
// To optimize the above algorithm we should stop the loop as soon as there is not even one swapping of elements in one complete traversal
// which means that the vector is already sorted
// To optimize, we can use a bool type variable which is initialised to 0 and if swap function is executed, the bool variable will become 1 
// when control comes out of the inner loop after one complete traversal, we can check if value of bool is zero or one
// and break if we need to end the for loop.

// The worst case and average time complexity of bubble sort is O(n^2).
// The best case scenario is when the vector is already sorted and then the time complexity would be O(n).
// 
// It is used in computer graphics for its capability to detect a very small error (like swap of just two elements) in almost-sorted vector 
// and fix it with just linear complexity (2n). 
// It is used in a polygon filling algorithm.

#include <iostream>
#include <vector>

using namespace std;

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubblesort(vector<int>& v) {
  for (int i = 0; i < v.size(); i++) {
  	bool ifswap = false;
  	for (int j = 0; j < v.size() - i; j++) {
  	  if (v[j] > v[j+1]) {
  	  	swap(&v[j],&v[j+1]);
  	  	ifswap = true;
  	  }
  	}
  	if (ifswap == false)
  	  break;
  }
}

void print(const vector<int>& v) {
  for (int i = 0; i < v.size(); i++) {
  	cout << v[i] << " ";
  }
  cout << endl;
}

int main() {
  vector<int> v {13, 4, 1, 42, 3, 6};
  cout << "Unsorted Vector: ";
  print(v);
  bubblesort(v);
  cout << "Sorted Vector: ";
  print(v);
  return 0;
}
