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
