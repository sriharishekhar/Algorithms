// Insertion sort
// Algo: At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. 
// Repeat until no input elements remain. 
// At each array-position, check the value there against the largest value in the sorted list 
// If larger, leave the element in place and move to the next
// If smaller, find the correct position within the sorted list, shift all the larger values up to make a space, and insert into that correct position.

// Time Complexity : O(n^2)

// Uses : 1. Insertion sort is used when number of elements is small. 
//        2. It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.

#include <iostream>
using namespace std;

void print(int a[], int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}

void insertion_sort(int a[], int n) {
  int i, j, key;
  for (i = 0; i <n; i++) {
    key = a[i];
    j = i - 1;
    while (j >= 0 && a[j]>key) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = key;
  }  
  print(a,n);
}

int main() {
  int a[] = {9, 8, 7, 1, 4, 3, 3, 1, 7 ,4};
  int n = sizeof(a)/sizeof(a[0]);
  insertion_sort(a,n);
  return 0;
}
