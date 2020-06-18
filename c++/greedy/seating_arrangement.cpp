#include <bits/stdc++.h>

using namespace std;

// Complexity: Time = O(n! * n), Space = O(1);
int getAwkwardness (vector<int>& arr) {
  int size = (int) arr.size();
  if (size == 0) {
    return 0;
  }
  int maxAwkward = abs (arr[0] - arr[size - 1]);
  for (int i = 1; i < (int) arr.size(); i++) {
    int currAwkward = abs (arr[i] - arr[i - 1]);
    maxAwkward = max (maxAwkward, currAwkward);
  }
  
  return maxAwkward;
}

int minOverallAwkwardness(vector <int> arr) {
  // Brute force based on permutations
  int size = (int) arr.size();
  if (size == 0) {
    return 0;
  }
  int minAwkward = INT_MAX;
  sort (arr.begin(), arr.end()); // O(n log n)
  do {
    int awkwardness = getAwkwardness(arr);
    minAwkward = min (minAwkward, awkwardness); // O(n)
  } while (next_permutation (arr.begin(), arr.end())); // O(n!)

  return minAwkward;
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

  vector <int> arr_1{5, 10, 6, 8};
  int expected_1 = 4;
  int output_1 = minOverallAwkwardness(arr_1);
  check(expected_1, output_1);

  vector <int> arr_2{1, 2, 5, 3, 7};
  int expected_2 = 4;
  int output_2 = minOverallAwkwardness(arr_2);
  check(expected_2, output_2);
}
