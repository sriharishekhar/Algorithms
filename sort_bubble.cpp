// Q. Optimized bubble sort
// Algo:
// Traverse the array and compare every next pair of elements
// if a[i] > a[i+1], swap a[i] & a[i+1]
// at the end of first traversal, the biggest element is at the last index of the array and hence is sorted
// needs at most n more traversals to sort every element and next traversals need only be till n - i
// for optimized bubble sort, we need to stop the loop as soon as no swap is done after one whole traversal
// initialize bool variable as false at the beginning of first for loop
// if swap is done, bool = true
// if bool == false after one complete traversal of inner loop, break.

#include <iostream>

using namespace std;

void print(int a[], int n) {
  for (int i = 0; i < n; i++) {
  	cout << a[i] << " ";
  }
  cout << endl;
}

void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void optimized_bubble_sort(int a[], int n) {
  for (int i = 0; i < n - 1; i++) {
  	bool ifswap = false;
  	for (int j = 0; j < n - i - 1; j++) {
  	  if (a[j] > a[j+1]) {
  	  	swap(a[j],a[j+1]);
  	  	ifswap = true;
  	  }
  	}
  	if(ifswap == false) {
  	  break;
  	}
  }
}

int main() {
  int a[] = {13, 4, 1, 42, 3, 6};
  int n = sizeof(a)/sizeof(a[0]);
  cout << "Unsorted array: ";
  print(a,n);
  optimized_bubble_sort(a,n);
  cout << "Sorted array: ";
  print(a,n);
  return 0;
}
