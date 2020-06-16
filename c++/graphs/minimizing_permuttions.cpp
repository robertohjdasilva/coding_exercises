Minimizing Permutations
In this problem, you are given an integer N, and a permutation, P of the integers from 1 to N, denoted as (a_1, a_2, ..., a_N). You want to rearrange the elements of the permutation into increasing order, repeatedly making the following operation:
Select a sub-portion of the permutation, (a_i, ..., a_j), and reverse its order.
Your goal is to compute the minimum number of such operations required to return the permutation to increasing order.
Signature
int minOperations(int[] arr)
Input
Size N is between 1 and 8
Array arr is a permutation of all integers from 1 to N
Output
An integer denoting the minimum number of operations required to arrange the permutation in increasing order
Example
If N = 3, and P = (3, 1, 2), we can do the following operations:
Select (1, 2) and reverse it: P = (3, 2, 1).
Select (3, 2, 1) and reverse it: P = (1, 2, 3).
output = 2

#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Complexity:  Time = O(N! * N ^ 2), Space = 
//
// Enhancement: Add reversed strings to a map and skip alreay processed strings
typedef enum {
  REVERSE_FORWARD = 0,
  REVERSE_BACKWARD
} direction;

int tryReversals(string& currStr, string& destStr, pair<string, int>& currPair,
                 queue<pair<string, int>>& qBFS, direction dirReversals) {
  int maxLen = (int) currStr.length();
  
  for (int prefixLen = 2; prefixLen <= maxLen; prefixLen++) {
    string reverseStr = currStr;
    // Reverse the string till prefix i - the end is supposed to be one character past the end
    if (dirReversals == REVERSE_FORWARD) {
      reverse(reverseStr.begin(), reverseStr.begin() + prefixLen);
    } else {
      reverse(reverseStr.begin() + maxLen - prefixLen, reverseStr.end());
    }
      
    // If after reversing the string from first i index 
    // it is equal to the destination string, we found the minimum
    // number of reversals
    if (reverseStr == destStr) { 
      return currPair.second + 1; 
    }
      
    // Push the reverse string to the queue, and increment the number of reversals
    qBFS.push({reverseStr, currPair.second + 1}); 
  }
  return -1;
}

int minOperations(vector <int> arr) {
  // Encode array into a string
  string origStr;
  for (int num : arr) { // O(n)
    origStr += to_string(num);
  }
  
  // Sort the string, which will give us a string corresponding to our final sorted list
  string destStr(origStr);
  sort(destStr.begin(), destStr.end()); // O(n log n)
  
  if (origStr == destStr) {
    return 0;
  }
  
  queue<pair<string, int>> qBFS; // string = currStr, int = reversals
  pair<string, int> currPair; // Auxiliary variable to hold a pair
  
  qBFS.push({origStr, 0});
  
  while (!qBFS.empty()) {
    // Get pair at front of queue
    currPair = qBFS.front();
    // Get current string
    string currStr = currPair.first;
    
    // Pop currently processed element
    qBFS.pop();
    
    // Peform prefix reversals for all possible indexes and push in
    // the queue and check for the minimum
    int reversals;
    reversals = tryReversals(currStr, destStr, currPair, qBFS, REVERSE_FORWARD);
    if (reversals != -1) {
      return reversals;
    }
    reversals = tryReversals(currStr, destStr, currPair, qBFS, REVERSE_BACKWARD);
    if (reversals != -1) {
      return reversals;
    }
  }
  
  // Something went wrong
  return -1;
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
  vector <int> arr_1{1, 2, 5, 4, 3};
  int expected_1 = 1;
  int output_1 = minOperations(arr_1);
  check(expected_1, output_1);

  int n_2 = 3;
  vector <int> arr_2{3, 1, 2};
  int expected_2 = 2;
  int output_2 = minOperations(arr_2);
  check(expected_2, output_2); 
}
