// Merge sort
// Algo: Divide & Conquer
// Divide unsorted list into two parts -> a[0..m] & a[m+1,...r]
// recursively divide further till size becomes 1
// a list of 1 element is supposed sorted
// Repeatedly merge sublists to produce newly sorted sublists until there is only 1 sublist remaining. This will be the sorted list.
// 
// Time Complexoty : O(nlogn)
//
// Uses : 1. Merge Sort is useful for sorting linked lists in O(nLogn) time
//        2. Inversion Count Problem
//        3. External Sorting
#include <iostream>

using namespace std;

void merge(int a[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;
  int L[n1], R[n2];
  int i, j, k;
  for (i = 0; i < n1; i++) {
    L[i] = a[l + i];
  }
  for (j = 0; j < n2; j++) {
    R[j] = a[m + 1 + j];
  }
  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      a[k++] = L[i];
      i++;
    }
    else {
      a[k++] = R[j];
      j++;
    }
  }
  while (i < n1) {
    a[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    a[k] = R[j];
    j++;
    k++;
  }
}

void merge_sort(int a[], int l, int r) {
  if (l < r) {
    int m = l + (r-l) / 2;
    merge_sort(a,l,m);
    merge_sort(a,m+1,r);
    merge(a,l,m,r);
  }  
}

void print(int a[], int n) {
  for (int i = 0; i < n; i++) {
  	cout << a[i] << " ";
  }
  cout << endl;
}

int main() {
  int a[] = {13, 4, 1, 42, 3, 6};
  int n = sizeof(a)/sizeof(a[0]);
  cout << "Unsorted array: ";
  print(a,n);
  merge_sort(a,0,n-1);
  cout << "Sorted array: ";
  print(a,n);
  return 0;
}
