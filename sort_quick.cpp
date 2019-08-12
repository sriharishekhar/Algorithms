// Quick sort
// Algo: Take last element as pivot
// place pivot at correct position
// arrange all elements smaller than pivot to the left
// arrange all elements bigger than pivot to the right

// Time Complexoty : O(nlogn)
// The sorting takes in-place and hence no extra memory is allocated

#include <iostream>
#include <vector>

using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void print(const vector<int>& v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

int partition(vector<int>& v, int first, int last) {
  int pivot = v[last];
  int i = first - 1;
  for (int j = first; j <= last - 1; j++) {
    if (v[j] <= pivot) {
      i++;
      swap(&v[i], &v[j]);
    }
  }
  swap (&v[i+1], &v[last]);
  return (i + 1);
}

void quick_sort(vector<int>& v, int first, int last) {
  if (first < last) {
    int partition_value = partition(v,first,last);
    quick_sort(v,first, partition_value-1);
    quick_sort(v, partition_value+1, last);
  }
}

int main() {
  vector<int> v = {13, 4, 1, 42, 3, 6};
  cout << "Unsorted Vector: ";
  print(v);
  quick_sort(v, 0, v.size()-1);
  cout << "Sorted Vector: ";
  print(v);
  return 0;
}
