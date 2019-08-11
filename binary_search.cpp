// Binary Search
// Algo:
// Binary search works on sorted arrays. 
// Binary search begins by comparing an element in the middle of the array with the target value. 
// If the target value matches the element, its position in the array is returned. 
// If the target value is less than the element, recursively search this half of the array. 
// If the target value is greater than the element, the recursively search this half of the array. 
// By doing this, the algorithm eliminates the half in which the target value cannot lie in each iteration.
//
// Time Complexity : Best case - O(1)
//                   Worts case - O(logn)

#include <iostream>
using namespace std;

int binary_search(int a[], int l, int r, int x) {
  if (r >= l) {
    int mid = (l + r) / 2;
    if (a[mid] == x) { 
      return mid;
    }  
    if (a[mid] > x) {
      return binary_search(a, l, mid-1, x);
    }
    if (a[mid] < x) {
      return binary_search(a, mid+1, r, x);
    }
  }
  return 1;
}

int main() {
  int a[] = {1, 2, 4, 6, 8 , 10, 15 ,18};
  int n = sizeof(a) / sizeof(a[0]);
  int x = 8;
  int result = binary_search(a, 0, n, x);
  if(result == 1) 
    cout << "Element not found" << endl;
  else
    cout << "Element found at position = "  << result << endl;
  return 0;
}
