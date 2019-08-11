// Selection sort
// Algo:
// We assume the element at the first index of the vector to be the smallest value element
// We put the address of this element in a variable minimum_index
// we traverse the vector and compare value of every element with the value of element at minimum_index
// if the value is lower than that at minimum_index, we will put the address of that element in minimum_index
// this way, at the end of the first traversal, we will have the address of smallest element at minimum_index
// we will then swap the value at minimum_index with the element at position(number of traversal,in this case 1 i.e element at index 0)
// Therefore, we will have the first element sorted
// do this for the remaining n - 1 elements from position 1 - n 

// Time complexity for selection sort is O(n*n)
// Use : As selection sort does sorting in-place, therefore it doesn't require any extra space.

#include <iostream>
#include <vector>

using namespace std;

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionsort(vector<int>& v) {
  for (int i = 0; i < v.size(); i++) {
  	int min_index = i;
  	for (int j = i; j < v.size(); j++) {
  	  if (v[j] < v[min_index]) {
  	  	min_index = j;
  	  }
  	}
  	swap (v[i],v[min_index]);
  }
}

void print(const vector<int>& v) {
  for (int i = 0; i < v.size(); i++) {
  	cout << v[i] << " ";
  }
  cout << endl;
}

int main() {
  vector<int> v {13,4,1,42,3,6};
  cout << "Unsorted Vector: ";
  print(v);
  selectionsort(v);
  cout << "Sorted Vector: ";
  print(v);
  return 0;
}
