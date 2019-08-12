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
#include <vector>

using namespace std;

void merge(vector<int>& v, int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;
  int L[n1], R[n2];
  int i, j, k;
  for (i = 0; i < n1; i++) {
    L[i] = v[l + i];
  }
  for (j = 0; j < n2; j++) {
    R[j] = v[m + 1 + j];
  }
  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      v[k++] = L[i];
      i++;
    }
    else {
      v[k++] = R[j];
      j++;
    }
  }
  while (i < n1) {
    v[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    v[k] = R[j];
    j++;
    k++;
  }
}

void merge_sort(vector<int>& v, int l, int r) {
  if (l < r) {
    int m = l + (r-l) / 2;
    merge_sort(v,l,m);
    merge_sort(v,m+1,r);
    merge(v,l,m,r);
  }  
}

void print(const vector<int>& v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main() {
  vector<int> v {13, 4, 1, 42, 3, 6};
  cout << "Unsorted array: ";
  print(v);
  merge_sort(v,0,v.size()-1);
  cout << "Sorted array: ";
  print(v);
  return 0;
}
