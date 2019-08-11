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
