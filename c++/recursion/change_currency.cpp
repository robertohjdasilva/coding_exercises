#include <bits/stdc++.h>

using namespace std;

// Example
// denominations = [5, 10, 25, 100, 200]
// targetMoney = 94
// output = false

bool canGetExactChange(int targetMoney, vector<int>& denominations){
  // amount         0  1  2  3  4  5  6  7  8  9  10 11 12
  // dp (init)      0  13 13 13 13 13 13 13 13 13 13 13 13
  // dp (using 1)   0  1  2  3  4  5  6  7  8  9  10 11 12
  // dp (using 5)   0  1  2  3  4  1  2  3  4  5  2  3  4
  // dp (using 10)  0  1  2  3  4  1  2  3  4  5  1  2  3
  if (denominations.size() == 0) return false;
  if (targetMoney <= 0) return false;
  
  // Initialize the dynamic programming array with targetMoney + 1.
  // The array stores the minimum number of coins needed to make a change.
  vector<int> dp(targetMoney + 1, targetMoney + 1);
  dp[0] = 0; // There is no way to make change for an amount of zero.
  for (int amount = 0; amount <= targetMoney; amount++) {
    for (int denom : denominations) {
      if (amount >= denom) {
        dp[amount] = min(dp[amount], 1 + dp[amount - denom]);
      }
    }
  }
  return (dp[targetMoney] < targetMoney + 1);
}

void printString(string& str) {
  cout << "[\"" << str << "\"]";
}

int test_case_number = 1;

void check(bool expected, bool output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printf("%s", expected ? "true" : "false");
    cout << " Your output: ";
    printf("%s", output ? "true" : "false");
    cout << endl; 
  }
  test_case_number++;
}

int main(){
  // Testcase 1
  int target_1 = 94;
  vector<int> arr_1{5, 10, 25, 100, 200};
  bool expected_1 = false;
  bool output_1 = canGetExactChange(target_1, arr_1); 
  check(expected_1, output_1); 
  
  // Testcase 2
  int target_2 = 75;
  vector<int> arr_2{4, 17, 29};
  bool expected_2 = true;
  bool output_2 = canGetExactChange(target_2, arr_2); 
  check(expected_2, output_2); 
  
  return 0; 
}
