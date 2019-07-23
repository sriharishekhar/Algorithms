#include <iostream>
#include <string>
#include <set>
#include <iterator>
using namespace std;

string remove_duplicates(string& s) {
  set < char > :: iterator itr;
  set < char > s2;
  string s3;
  char b;
  for (int i = 0; i < s.size(); i++) {
  	b = s[i];
  	s2.insert(b);
  }
  for (itr = s2.begin(); itr != s2.end(); itr++) {
  	b = *itr;
  	s3.push_back(b);
  }
  return s3;
}

int main() {
  string s("abrownbearisridingabike");
  cout << remove_duplicates(s) << " " << endl;
  return 0;
}