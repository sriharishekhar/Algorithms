// Q. Reverse a string
// Algo : 
// Start two indexes, one at 0 and one at n-1
// swap elements at both these indexes
// increment left side index by 1 and decrement right side index by 1 and keep swapping till you reach mid
//
// Time Complexity : O(n)

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
