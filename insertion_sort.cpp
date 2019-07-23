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
