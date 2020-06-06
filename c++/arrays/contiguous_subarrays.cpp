#include <bits/stdc++.h>

using namespace std;

// Example:
// Input = [3, 4, 1, 6, 2]
// Output = [1, 3, 1, 5, 1]
//
// Complexity: Time = O(n ^ 2), Space = O(1)
// n * (n - 1)

vector <int> CountSubarrays(vector <int> arr) {
  int size = (int) arr.size();
  if (size == 0) return {};
  
  vector<int> subarrayCount;
  
  for (int i = 0; i < size; i++) {
    int elementCount = 1;
    int currElement = arr[i];
    int index;
    // Subarrays at left
    index = i - 1;
    while (index >= 0 && arr[index] <= currElement) {
      elementCount++;
      index--;
    }
    // Subarrays at right
    index = i + 1;
    while (index < size && arr[index] <= currElement) {
      elementCount++;
      index++;
    }
    // Add count to result
    subarrayCount.push_back (elementCount);
  }
  
  return subarrayCount;
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

  vector <int> test_1{3, 4, 1, 6, 2};
  vector <int> expected_1{1, 3, 1, 5, 1};
  vector <int> output_1 = CountSubarrays(test_1);
  check(expected_1, output_1);

  vector <int> test_2{2, 4, 7, 1, 5, 3};
  vector <int> expected_2{1, 2, 6, 1, 3, 1};
  vector <int> output_2 = CountSubarrays(test_2);
  check(expected_2, output_2); 
}
