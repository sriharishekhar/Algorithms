// Quick sort
// Algo: Take last element as pivot
// place pivot at correct position
// arrange all elements smaller than pivot to the left
// arrange all elements bigger than pivot to the right

// Time Complexoty : O(nlogn)
// The sorting takes in-place and hence no extra memory is allocated


#include <iostream>

using namespace std;

void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void print(int a[], int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

int partition(int a[], int low, int high) {
  int pivot = a[high];
  int i = low - 1;
  for (int j = low; j <= high - 1; j++) {
    if (a[j] <= pivot) {
      i++;
      swap(&a[i], &a[j]);
    }
  }
  swap (&a[i + 1], &a[high]);
  return (i + 1);
}

void quick_sort(int a[], int low, int high) {
  if (low < high) {
    int partition_value = partition(a,low,high);
    quick_sort(a,low, partition_value-1);
    quick_sort(a, partition_value+1, high);
  }
}

int main() {
  int a[] = {13, 4, 1, 42, 3, 6};
  int n = sizeof(a)/sizeof(a[0]);
  cout << "Unsorted array: ";
  print(a,n);
  quick_sort(a, 0, n-1);
  cout << "Sorted array: ";
  print(a,n);
  return 0;
}
