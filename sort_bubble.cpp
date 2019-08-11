// Q. Bubble sort
// Algo:
// Assume that first element is the biggest element in the array
// Traverse the array(from 0 to n) and copmare every consecutive pair of elements
// if the value of the element at the lower index is bigger than the value of the element at the higher index, swap them
// do this for one complete traversal of the array, it would bring the largest element at the last index and hence that index is sorted
// if we have n elements then we have to sort for the remaining n - 1 elements, as last element is now already sorted
// we would at most need to run the loop n - 1 more times to sort every element in the worst case scenario
// therefore we would need to run two nested for loops to execute the above algorithm
// To optimize the above algorithm we should stop the loop as soon as there is not even one swapping of elements in one complete traversal
// which means that the array is already sorted
// To optimize, we can use a bool type variable which is initialised to 0 and if swap function is executed, the bool variable will become 1 
// when control comes out of the inner loop after one complete traversal, we can check if value of bool is zero or one
// and break if we need to end the for loop.

// The worst case and average time complexity of bubble sort is O(n^2).
// The best case scenario is when the array is already sorted and then the time complexity would be O(n).
// 
// It is used in computer graphics for its capability to detect a very small error (like swap of just two elements) in almost-sorted arrays 
// and fix it with just linear complexity (2n). 
// It is used in a polygon filling algorithm.

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
  int a = {13, 4, 1, 42, 3, 6};
  int n = sizeof(a)/sizeof(a[0]);
  cout << "Unsorted array: ";
  print(a,n);
  optimized_bubble_sort(a,n);
  cout << "Sorted array: ";
  print(a,n);
  return 0;
}
