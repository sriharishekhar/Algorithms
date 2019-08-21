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
  BigInteger(string& s1, string& s2) {
    CheckStringIfNegative(s1,s2);
    CheckBigger(s1,s2);
    std::reverse(s1.begin(), s1.end());
    std::reverse(s2.begin(), s2.end());
    StringToVector(s1,s2);
    if (s1negative_ == true && s2negative_ == false) {
      if (equal_ == true) {
        cout << "0" << endl;
      }
      else {
        AddIfNegative(v1_,v2_);
      }
    } 
    if (s1negative_ == false && s2negative_ == true) {
      if (equal_ == true) {
        cout << "0" << endl;
      }
      else {
        AddIfNegative(v1_,v2_);
      }
    }  
    if (s1negative_ == true && s2negative_ == true) {
      Add(v1_,v2_);  
    }
    if (s1negative_ == false && s2negative_ == false) {
      Add(v1_,v2_);
    }
  }

  void CheckStringIfNegative(string& s1, string& s2) {
    if (s1[0] == '-') {
      s1negative_ = true;
      for (int i = 0; i < s1.size() - 1; i++) {
        s1[i] = s1[i+1];
      }
      s1.resize(s1.size()-1);
    }
    else {
      s1negative_ = false;
    }
    
    if (s2[0] == '-') {
      s2negative_ = true;
      for (int i = 0; i < s2.size() - 1; i++) {
        s2[i] = s2[i+1];
      }
      s2.resize(s2.size()-1);
    }
    else {
      s2negative_ = false;
    }
  }

  void CheckBigger(string& s1, string& s2) {
    if (s2.size() > s1.size()) {
      SwapString(s1,s2);
      s1big_ = true;
      if (swap_ == true) {
        SwapSign(s1negative_,s2negative_);
      }
    } 
    else if (s1.size() == s2.size()) {
      int i = 0;
      equal_ = true;
      while (i < s1.size()) {
        if (s1[i] > s2[i]) {
          s1big_ = true;
          s2big_ = false;
          equal_ = false;
          break;
        }
        else if (s1[i] < s2[i]) {
          s2big_ = true;
          s1big_ = false;
          equal_ = false;
          break;
        }
      i++;
      }  
      if (s2big_ == true) {
        SwapString(s1,s2);
        if (swap_ == true) {
          SwapSign(s1negative_,s2negative_);
        }
      }
    }  
    else if (s1.size() > s2.size()){
      s1big_ = true;
    } 
  }

  void SwapString(string& s1, string& s2) {
    string temp = s1;
    s1 = s2;
    s2 = temp;
    swap_ = true;
  }

  void SwapSign(bool& s1negative_, bool& s2negative_) {
    bool temp = s1negative_;
    s1negative_ = s2negative_;
    s2negative_ = temp;
  }

  void StringToVector(string& s1, string& s2) {
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
  }

  void AddIfNegative(vector<int> v1_, vector<int> v2_) {
    for (int i = 0; i < v1_.size(); i++) {
      if (v1_[i] < v2_[i]) {
        
        v1_[i] = v1_[i] + 10;
        int difference = v1_[i] - v2_[i];
        result_.push_back(difference);
        int j = 1;
        
        if (v1_[i+j] == 0) {
          while (v1_[i+j] == 0) {
            v1_[i+j] = 9;
            j++;
          }
          v1_[i+j] = v1_[i+j] - 1;
        }
        else {
          v1_[i+j] = v1_[i+j] - 1;
        }
      }
      
      else if (v1_[i] > v2_[i]) {
        int difference = v1_[i] - v2_[i];
        result_.push_back(difference);
      }
      else if (v1_[i] == v2_[i]) {
        result_.push_back(0);       
      }     
    }
    std::reverse(result_.begin(),result_.end());
    PrintIfNegative();
  } 

  void PrintIfNegative() {
    if (s1negative_ == true) {
      cout << "-";
      for (int i = 0; i < result_.size(); i++) {
        cout << result_[i];
      }
      cout << endl;
    }
    if (s2negative_ == true) {
      for (int i = 0; i < result_.size(); i++) {
        cout << result_[i];
      }
      cout << endl;    
    }
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
      if (i == v1_.size() - 1) {
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
    if (s1negative_ == true && s2negative_ == true) {
      cout << "-";
      for (int i = 0; i < result_.size(); i++) {
        cout << result_[i];
      }
    }
    else {
      for (int i = 0; i < result_.size(); i++) {
      cout << result_[i];
      }
    }
    cout << endl;
  }

 private:
  bool swap_;
  bool equal_;
  bool s1big_;
  bool s2big_;
  bool s1negative_;
  bool s2negative_;
  std::vector<int> v1_;
  std::vector<int> v2_;
  std::vector<int> result_;
};

int main() {
  string s1, s2;
  s1 = "100000000000000000000";
  s2 = "20000000000000000";
  BigInteger number(s1,s2);
  return 0;
}
