// Reverse a string
// Algorithm -
// mid = (index of first character + size of string) / 2
// while (n > mid)
// swap(character at index 0 i.e first, character at index n i.e n)
// n--;
// first ++

#include <iostream>
#include <string>
using namespace std;

void swap (char *a, char *b) {
  char temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void reverse_string(string& s) {
  int n = s.length();
  int i = 0;
  int mid = n / 2;
  while (n > mid) {
  	swap (&s[i], &s[n - 1]);
  	n--;
  	i++;
  }
  cout << "String after reversing : ";
  cout << s << endl;
}

int main() {
  string s("amanisknownforhisvalues");
  cout << "String before reversing : " << s <<endl;
  reverse_string(s);
  return 0;
}