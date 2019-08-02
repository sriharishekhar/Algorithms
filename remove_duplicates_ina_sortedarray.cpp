//Q. Remove duplicates in a sorted array
// Algo : 
// Traverse the string. For first traversal
// We will compare first element of string s i.e s[0] with the next elements
// till s[0] is not equal to the next element
// when the next element i.e s[j] is not equal to s[i] 
// replace s[i+1] with s[j]
// Do this for every traversal of i
// Store last element as it is, as it wouldn't have been stored before.

#include <iostream> 
#include <string>
using namespace std; 

int removeDuplicates(string& s) 
{ 
  string temp_string;  
  int j = 0; 
  for (int i = 0; i < s.size() - 1; i++) { 
    if (s[i] != s[i+1]) {
      temp_string[j++] = s[i]; 
    }
  }  
  temp_string[j++] = s[s.size()-1]; 
  for (int i = 0; i < j; i++) { 
    s[i] = temp_string[i]; 
  }  
  return j; 
} 

int main() 
{ 
  string s("aaaabbccdeeeffghiimnnpssuvwwxyyz");
  int n = removeDuplicates(s); 
  for (int i = 0; i < n-1; i++) { 
    cout << s[i] << " "; 
  }
  return 0; 
}
