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

int binary_search(vector<int>& v, int left, int right, int value) {
  if (left > right || left >= v.size()) return -1;
  if (left <= right) {
  	int mid = left + (right - left) / 2;
  	if (v[mid] == value) return mid;
  	if (value < v[mid]) return binary_search(v,left,mid-1,value);
  	else return binary_search(v,mid+1,right,value);
  }
  return -1;
}

int main() {
  vector<int> v {5, 7, 101, 4555, 7777, 6768865};
  int value = 42;
  int position = binary_search(v,0,v.size(),value);
  if (position == -1) {
    cout << "Element not found" << endl;
  }
  else {
    cout << "Element found at: " << position << endl;
  }
}
