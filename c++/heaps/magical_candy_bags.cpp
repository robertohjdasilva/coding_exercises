#include <bits/stdc++.h>

using namespace std;

// Example 1
// N = 5 
// K = 3
// arr = [2, 1, 7, 4, 2]
// output = 14

int maxCandies(vector <int> arr, int k) {
  int size = (int) arr.size();
  if (size == 0) return 0;
  
  priority_queue<int> candyCountHeap;
  for (int num : arr) {
    candyCountHeap.push (num);
  }
  
  int candiesEaten = 0;
  for (int i = 0; i < k; i++) { // i = 2
    int maxCount = candyCountHeap.top(); // = 3
    candiesEaten += maxCount; // = 14
    candyCountHeap.pop();
    candyCountHeap.push(floor(maxCount/2));
  }
  return candiesEaten;
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

  int n_1 = 5, k_1 = 3;
  vector <int> arr_1{2, 1, 7, 4, 2};
  int expected_1 = 14;
  int output_1 = maxCandies(arr_1, k_1);
  check(expected_1, output_1);

  int n_2 = 9, k_2 = 3;
  vector <int> arr_2{19, 78, 76, 72, 48, 8, 24, 74, 29};
  int expected_2 = 228;
  int output_2 = maxCandies(arr_2, k_2);
  check(expected_2, output_2);
}
