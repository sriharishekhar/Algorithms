// Insertion sort
// Algo: At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. 
// Repeat until no input elements remain. 
// At each vector-position, check the value there against the largest value in the sorted list 
// If larger, leave the element in place and move to the next
// If smaller, find the correct position within the sorted list, shift all the larger values up to make a space, and insert into that correct position.

// Time Complexity : O(n^2)

// Uses : 1. Insertion sort is used when number of elements is small. 
//        2. It can also be useful when input vector is almost sorted, only few elements are misplaced in complete big vector.

#include <iostream>
#include <vector>

using namespace std;

void insertionsort(vector<int>& v) {
  for (int i = 1; i < v.size(); i++) {
  	int j, key;
    j = i - 1;
    key = v[i];  
  	while (j >= 0 && v[j] > key) {
      v[j+1] = v[j];
      j--;
    }
    v[j+1] = key;
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
  insertionsort(v);
  cout << "Sorted Vector: ";
  print(v);
  return 0;
}
