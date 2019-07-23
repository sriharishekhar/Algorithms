#include<iostream>
#include<string>
using namespace std;

void remove_duplicates(string& s) {
  string s2;
  int n = s.length();
  int j;
  
  for (int i = 0; i < n; i++) {
    for (j = 0; j < i; j++) {
      if (s[i]==s[j]) {
        break;
      }
    }
    if (i == j) {
      s2.push_back(s[i]);  
    }
  }
  cout << s2 << endl;
}    
  
int main() {
  string s("abrownfoxjumpedupanddown");
  remove_duplicates(s);
  return 0; 
}