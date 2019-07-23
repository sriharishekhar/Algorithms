#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

void swap(int *v1, int *v2) {
  int temp;
  temp = *v1;
  *v1 = *v2;
  *v2 = temp; 
}

void display(vector <char> &v) {
  for (int i = 0; i < v.size(); i++) {
  	cout << v[i] << " ";
  }
}

void selection_sort(vector <char> v) {
  vector <char> :: iterator itr1;
  vector <char> :: iterator itr2;
  vector <char> :: iterator itr3;
  int a;
  for (itr1 = v.begin(); itr1 < v.end(); itr1++) {
  	itr3 = itr1;
  	for ( itr2 = itr1; itr2 != v.end(); itr2++) {
      if (v[a] > *itr2) {
      	a = itr2;
      } 	   
  	}
  	swap (v[a], v[itr1]);
  }	
  display(v);
}

int main() {
  string s("amanjumpedoverabuilding");	
  vector <char> v (s.begin(), s.end());
  cout << v;
  selection_sort(v);
  return 0;
}