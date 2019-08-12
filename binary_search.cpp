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
#include <vector>

using namespace std;

int binary_search(vector<int>& v, int l, int r, int x) {
  if (l <= r) {
  	int mid = l + (r - l) / 2;
  	if (v[mid] == x) 
  	  return mid;
  	if (x < v[mid])
  	  return binary_search(v,l,mid-1,x);
  	else 
  	  return binary_search(v,mid+1,r,x);
  }
  return -1;
}

int main() {
  vector<int> v {13, 4, 1, 42, 3, 6};
  int x = 42;
  int position = binary_search(v,0,v.size(),x);
  if (position == -1) {
    cout << "Element not found" << endl;
  }
  else {
    cout << "Element found at: " << position << endl;
  }
}
