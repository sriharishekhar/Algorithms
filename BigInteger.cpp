// Problem: Implement a BigInteger class that supports addition on arbitarirly large numbers.
// We can have numbers upto 10 ^ 18 in long int. BigInteger should support number larger than
// this limit.
// For example - 100000000000000000000 + 100000000000000000000 = 200000000000000000000

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BigInteger {
 public:
  BigInteger(std::string& s1, std::string& s2) {
    std::reverse(s1.begin(), s1.end());
    std::reverse(s2.begin(), s2.end());
    if (s2.size() > s1.size()) {
      string temp = s1;
      s1 = s2;
      s2 = temp; 
    } 
    for (int i = 0; i < s1.size(); i++) {
      v1_.push_back(s1[i] - 48);
    }
    for (int i = 0; i < s2.size(); i++) {
      v2_.push_back(s2[i] - 48);
    }
    if (v1_.size() > v2_.size()) {
      for (int i = v2_.size(); i < v1_.size(); i++) {
        v2_.push_back(0);
      }
    }
    Add(v1_,v2_);
  }

  void Add(vector<int> v1_, vector<int> v2_) {
    int carry = 0;
    for (int i = 0; i < v1_.size(); i++) {
      int sum = v1_[i] + v2_[i] + carry;
      string str_sum = std::to_string(sum);
      int onesdigit;
      if (str_sum.size() == 1) {
        onesdigit = str_sum[0] - 48;
        carry = 0;
      }
      else {
        onesdigit = str_sum[1] - 48;
        carry = str_sum[0] - 48;
      }
      if (i == v1_.size()) {
        result_.push_back(sum);
      }
      else {
        result_.push_back(onesdigit);
      }
    }
    std::reverse(result_.begin(),result_.end());
    Print();
  }

  void Print() {
    for (int i = 0; i < result_.size(); i++) {
      cout << result_[i];
    }
    cout << endl;
  }

 private:
  std::vector<int> v1_;
  std::vector<int> v2_;
  std::vector<int> result_;
};

int main() {
  string s1, s2;
  cout << "Enter two numbers" << endl;
  cin >> s1;
  cin >> s2;
  BigInteger number(s1,s2);
  return 0;
}
