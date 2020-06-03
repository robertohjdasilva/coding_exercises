#include <bits/stdc++.h>

using namespace std;

// Example 1
// n = 2
// arr = [2, 1]
// output = [2, 2]
//
// Example 2
// n = 2
// arr = [1, 2]
// output = [1, 1]

// Complexity
// Time = O(n ^ 2), Space = O(1)
vector <int> findSignatureCounts(vector <int> arr) {
    int size = (int) arr.size ();
    if (size == 0) return {};
    
    vector<int> signatures (size, 1);
    
    for (int student = 0; student < size; student++) {
      // student and nextIndex are 0-based
      // arr[i] provides a 1-based index
      int nextIndex = arr[student] - 1;
      while (nextIndex != student) {
        signatures[student]++;
        nextIndex = arr[nextIndex] - 1;
      }
    }
    return signatures;  
}

void printIntegerVector(vector <int> array) {
  int size = array.size();
  cout << "[";
  for (int i = 0; i < size; i++) {
    if (i != 0) {
      cout << ", ";
    }
   cout << array[i];
  }
  cout << "]";
}

int test_case_number = 1;

void check(vector <int>& expected, vector <int>& output) {
  int expected_size = expected.size();
  int output_size = output.size();
  bool result = true;
  if (expected_size != output_size) {
    result = false;
  }
  for (int i = 0; i < min(expected_size, output_size); i++) {
    result &= (output[i] == expected[i]);
  }
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printIntegerVector(expected);
    cout << " Your output: ";
    printIntegerVector(output);
    cout << endl;
  }
  test_case_number++;
}

int main() {
  int n_1 = 2;
  vector <int> arr_1{2, 1};
  vector <int> expected_1{2, 2};
  vector <int> output_1 = findSignatureCounts(arr_1);
  check(expected_1, output_1);

  int n_2 = 2;
  vector <int> arr_2{1, 2};
  vector <int> expected_2{1, 1};
  vector <int> output_2 = findSignatureCounts(arr_2);
  check(expected_2, output_2);
}
