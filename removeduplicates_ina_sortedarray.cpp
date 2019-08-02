//Q. Remove duplicates in a sorted array
// Algo : Take first element and compare it with the next elements till 
// first element is not equal with it. 
// If index where first element is not equal with the incremented value is index_x
// then elements from address index_x to n will replace from the second element in the array to further
// For every index i, do the above

#include <iostream>
#include <string>

using namespace std;

void remove_duplicates(string &s) {
  for (int i = 0; i < s.length(); i++) {
  	int index = 1;
  	for (int j = i; j < s.length(); j++) {
  	  if (s[i] != s[j]) {
  	  	s[i+(index++)] = s[j];
  	  } 
  	}
  }
  cout << s << endl;
}

int main() {
  string s("aaabbccc");
  remove_duplicates(s);
  return 0;
}