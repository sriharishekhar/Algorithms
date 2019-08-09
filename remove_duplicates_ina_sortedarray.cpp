//Q. Remove duplicates in a sorted array
// Algo : 

#include <iostream> 
#include <string>
using namespace std; 

string removeDuplicates(string& s) 
{ 
  string temp_string;  
  int j = 0; 
  for (int i = 0; i < s.size() - 2; i++) { 
    if (s[i] != s[i+1]) {
      temp_string[j++] = s[i]; 
    }
  } 
  if () 
  return temp_string; 
} 

int main() 
{ 
  string s("aaaabbccdeeeffghiimnnpssuvwwxyyz");
  string s2 = removeDuplicates(s); 
  for (int i = 0; i < s2.size(); i++) { 
    cout << s2[i] << " "; 
  }
  return 0; 
}
