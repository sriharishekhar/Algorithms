// Problem: Implement a BigInteger class that supports addition on arbitarirly large numbers.
// We can have numbers upto 10 ^ 18 in long int. BigInteger should support number larger than
// this limit.
// For example - 100000000000000000000 + 100000000000000000000 = 200000000000000000000

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BigInteger {
private:

public:
  string s1;
  string s2;
  vector<int> v1;
  vector<int> v2;
  vector<int> result;

  void Stringtovector() {
    for (int i = 0; i < s1.size(); i++) {
      v1.push_back(s1[i] - 48);
    }
    for (int i = 0; i < s2.size(); i++) {
      v2.push_back(s2[i] - 48);
    }
    if (s1.size() > s2.size()) {
      for (int i = s2.size(); i < s1.size(); i++) {
        v2.push_back(0);
      }
    }
  }
  void Add() {
    for (int i = 0; i < v1.size(); i++) {
      int sum, onesdigit, carry, final;
      string string;
      carry = 0;
      sum = v1[i] + v2[i];
      string = sum;
      onesdigit = string[1];
      carry = string[0];
      final = onesdigit + carry;
      result.push_back(final);
    }
  }
  void Print() {
    reverse(result.begin(), result.end());
      for (int i = 0; i < result.size(); i++) {
      cout << result[i];
    }
  cout << endl;
  }
};

int main() {
  BigInteger number;
  cout << "Enter two numbers" << endl;
  cin >> number.s1;
  cin >> number.s2;
  reverse(number.s1.begin(), number.s1.end());
  reverse(number.s2.begin(), number.s2.end());
  if (number.s2.size() > number.s1.size()) {
    string temp = number.s1;
    number.s1 = number.s2;
    number.s2 = temp; 
  }
  number.Stringtovector();
  number.Add();
  number.Print();
  return 0;
}