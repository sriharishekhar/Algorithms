//Q. Remove duplicates in a sorted array
// Algo : Array is sorted, so we copy element when a new element appears
// run a foor loop i 
// if s[i] is not equal to s[index] where index is initialized to 0, copy s[i] over s[index + 1]
// next, when s[i] != s[index], move new s[i] to next position of s[index]
// do this for every value of i 
// the string now(without duplicates) should contain index number of elements i.e new size of string = index + 1

#include <iostream>
#include <string>

using namespace std;

void remove_duplicate(string& s) {
  int index = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != s[index]) {
      s[++index] = s[i];
    }
  }
  s.resize(index+1);
}

void print(const string& s) {
  cout << "String after duplicates are removed: ";
  for (int i = 0; i < s.size(); i++) {
    cout << s[i];
  }
  cout << endl;  
}

int main() {
  
  string s = "aabbbcccddefgghhhijjklmssuuswxyyzzzz";
  cout << "String before duplicates are removed: " << s << endl;
  remove_duplicate(s);
  print(s);

  return 0;
}
