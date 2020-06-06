#include <bits/stdc++.h>

using namespace std;

// Example
// s = "dcbefebce"
// t = "fd"'
// output = 5
//
// Complexity: Time = O(sLen), Space = O(tLen)

int minLengthSubstring(string s, string t) {
  int minLen = INT_MAX;
  int wStart = 0;
  int sLen = (int) s.length();
  int tLen = (int) t.length();
  if (sLen < tLen) return -1;
  
  // Add all t characters to an map.
  unordered_map<char, int> tCharCount; // key = ch, value = count
  for (int i = 0; i < tLen; i++) {
    tCharCount[t[i]]++;
  }
  
  int sMatch = 0;
  for (int wEnd = 0; wEnd < sLen; wEnd++) {
    char chEnd = s[wEnd];
    if (tCharCount.find (chEnd) != tCharCount.end() && tCharCount[chEnd] > 0) {
      tCharCount[chEnd]--;
      if (++sMatch == tLen) {
        minLen = min (minLen, wEnd - wStart + 1);
        // Move start of sliding window
        char chStart = s[wStart];
        wStart++;
        if (tCharCount.find (chStart) != tCharCount.end()) {
          tCharCount[chEnd]++;
          sMatch--;
        }
      }
    }
  }
  return minLen == INT_MAX ? -1 : minLen;
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

  string s_1 = "dcbefebce";
  string t_1 = "fd";
  int expected_1 = 5;
  int output_1 = minLengthSubstring(s_1, t_1);
  check(expected_1, output_1);

  string s_2 = "bfbeadbcbcbfeaaeefcddcccbbbfaaafdbebedddf";
  string t_2 = "cbccfafebccdccebdd";
  int expected_2 = -1;
  int output_2 = minLengthSubstring(s_2, t_2);
  check(expected_2, output_2);
  
}
