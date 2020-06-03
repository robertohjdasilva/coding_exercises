#include <bits/stdc++.h>

using namespace std;

// Example 1
// s = "abcd"
// t = "adcb"
// output = 4
//
// Example 2
// s = "mno"
// t = "mno"
// output = 1


int matchingPairs(string s, string t) {
  int len = (int) s.length();
  if (len < 2 || len != (int) t.length()) {
    return -1;
  }

  vector<int> swapIndexes;
  int matchCount = 0;
  for (int i = 0; i < len; i++) {
    if (s[i] == t[i]) {
      matchCount++;
    } else {
      if (swapIndexes.size() < 2) {
        swapIndexes.push_back (i);
      }
    }
  }
      
  switch (swapIndexes.size()) {
    case 0:
      return matchCount - 2;
    case 1:
      return matchCount - 1;
    case 2:
      if (s[swapIndexes[0]] == t[swapIndexes[1]]) matchCount ++;
      if (s[swapIndexes[1]] == t[swapIndexes[0]]) matchCount ++;
      return matchCount;
    default:
      return -1;
  }
}

void printInteger(int n) {
  cout << "[" << n << "]";
}

int test_case_number = 1;

void check(int expected, int output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printInteger(expected); 
    cout << " Your output: ";
    printInteger(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {
  int n_1 = 5;
  string s_1 = "abcde";
  string t_1 = "adcbe";
  int expected_1 = 5;
  int output_1 = matchingPairs(s_1, t_1);
  check(expected_1, output_1);

  string s_2 = "abcd";
  string t_2 = "abcd";
  int expected_2 = 2;
  int output_2 = matchingPairs(s_2, t_2);
  check(expected_2, output_2);
  
}
