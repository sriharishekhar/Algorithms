//Q. Remove duplicates in a sorted array
// Algo : 

#include <iostream>
#include <string>

using namespace std;

void remove_duplicate_ina_sortedarray(string& s) {
  for (int i = 0; i < s.size(); i++) {
    int index = i + 1;
    for (int j = i; j < s.size(); j++) {
      if (s[i] != s[j]) {
        s[index] = s[j];
        index++;
      }
      if (i == s.size() - 1) {
        int k = i;
        while (s[k] == s[k-1]) {
          s.pop_back();
          k--;
        }
      }
    }
  }
}

void print(string s) {
  cout << "String after duplicates are removed: ";
  for (int i = 0; i < s.size(); i++) {
    cout << s[i];
  }
  cout << endl;  
}

int main() {
  
  string s = "aabbbcccddefgghhhijjklmssuuswxyyzz";
  cout << "String before duplicates are removed: " << s << endl;
  remove_duplicate_ina_sortedarray(s);
  print(s);

  return 0;
}
