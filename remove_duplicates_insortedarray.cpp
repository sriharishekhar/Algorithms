// Q. Remove all duplicates from a sorted string.
// Algorithm 1 - Using set. Copy all elements from string to set. 
//				 As set takes no duplicate value. Program will run in o(n)

#include <iostream>
#include <set>
#include <iterator>
using namespace std;

string remove_duplicate(string& s) {
  string s2;
  set <char> s1;
  set <char> :: iterator it;
  for (int i = 0; i < s.length(); i++) {
  	s1.insert(s[i]);
  }
  for (it = s1.begin(); it != s1.end(); it++) {
  	s2.push_back(*it);
  }
  return s2;
}

int main() {
  string s("aaabbccccdddddddeeeeeefffffhhiijjkkkllllmmmmnnnnoooppqqrsstttuuvvwwwxxxyyzzzz");
  cout << remove_duplicate(s);
  return 0;
}