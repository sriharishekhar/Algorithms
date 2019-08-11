// Selection sort
// Algo:
// We assume the element at the first index of the array to be the smallest value element
// We put the address of this element in a variable minimum_index
// we traverse the array and compare value of every element with the value of element at minimum_index
// if the value is lower than that at minimum_index, we will put the address of that element in minimum_index
// this way, at the end of the first traversal, we will have the address of smallest element at minimum_index
// we will then swap the value at minimum_index with the element at position(number of traversal,in this case 1 i.e element at index 0)
// Therefore, we will have the first element sorted
// do this for the remaining n - 1 elements from position 1 - n 

// Time complexity for selection sort is O(n*n)
// Use : As selection sort does sorting in-place, therefore it doesn't require any extra space.

#include <iostream>
using namespace std;

void swap (int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void print (int a[], int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}

void selection_sort(int a[], int n) {
  int min_index;
  for (int i = 0; i < n; i++) {
    min_index = i;
    for (int j = i; j < n; j++) {
      if (a[min_index] > a[j]) 
        min_index = j;
    }
    swap (&a[min_index], &a[i]);
  }
  print(a, n);
  cout << endl;
}

int main() {
  int a[] = {8,9,12,5,0,4};
  int n = sizeof(a)/sizeof(a[0]);
  selection_sort(a,n);
  return 0;
} 
