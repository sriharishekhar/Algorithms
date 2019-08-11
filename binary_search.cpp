
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
