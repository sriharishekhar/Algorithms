#include <iostream>
#include <vector>
using namespace std;

void print(vector <int> &v) {
  vector <int> :: iterator itr;
  for (itr = v.begin(); itr < v.end(); itr++) {
    cout << *itr << " ";
  }
}

void insertion_sort(vector <int> v) {
  int i, j, key;
  for (i = 0; i < v.size(); i++) {
    j = i - 1;
    key = v[i];
    while (j >= 0 && v[j] > key) {
      v[j+1] = v[j];
      j--;
    }
    v[i] = key;
  }
  print(v);
}

int main() {
  int a[] = {9,8,7,1,4,3,3,1,7,4};
  int n = sizeof(a)/sizeof(a[0]);  
  vector <int> v(a, a + n);
  return 0;
}
