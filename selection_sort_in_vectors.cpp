#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

void swap (vector <char> &v, int min, int j) {
  int temp;
  temp = v[min];
  v[min] = v[j];
  v[j] = temp; 
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
  int min, i, j;
  for (i = 0; i < v.size(); i++) {
  	min = i;
  	for (j = i; j < v.size(); j++) {
      if (v[min] > v[j]) {
      	min = j;
      } 	   
  	}
  	swap (v,min,j);
  }	
  display(v);
}

int main() {
  string s("amanjumpedoverabuilding");	
  vector <char> v (s.begin(), s.end());
  selection_sort(v);
  return 0;
}
