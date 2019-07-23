#include <iostream>
#include <string>

using namespace std;

string remove_duplicates(string& s) {
  string no_dup;
  for (int i = 0; i < s.size(); ++i) {
    bool repeated = false;
    for (int j = 0; j < i; ++j) {
      if (s[i] == s[j]) { 
        repeated = true;
      }
    }
    if (!repeated) {
     no_dup.push_back(s[i]);
    }
  }
  return no_dup;
}


int main() {
  string s = "abrownfoxjumpedupanddown";
  string no_dup = remove_duplicates(s);
  cout << no_dup << endl;
}

