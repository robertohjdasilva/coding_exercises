#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Solution: Greedy algorithm - better than finding all permutations, checking how many differ by k elements
// and keep track of the minimum array.
//
// 1. Loop from the 0-th index of the array to the last index of the array as long as k is non-zero.
// 2. For each element, find the smallest element in the array which is smaller than the current
//    element and can be swapped with the current element in at most k swaps.
// 3. Swap the found element with the current element and update the value of k.
//
// Example: [5, 3, 1], k = 2
// k = 2, index = 0, minK = 1 => swap 1 and 5 => [1, 3, 5], decrement k
// k = 1, index = 1, minK = 5 => swap 3 and 5 => [1, 5, 3], decrement k
// exit
//
// Example 2: [8, 9, 11, 2, 1], k = 3
// k = 3, index = 0, minK = 2 => swap 2 and 8 => [2, 9, 11, 8, 1], decrement k
// k = 2, index = 1, minK = 8 => swap 9 and 8 => [2, 8, 11, 9, 1], decrement k
// k = 1, index = 2, minK = 9 => swap 11 and 9 => [2, 8, 9, 11, 1], decrement k
// exit
//
// Complexity: Time = O(n ^ 2), Space = O(1)
int getMinK(vector<int>&arr, int index, int k, int size) {
  int minValue = INT_MAX;
  int minKIndex = index;
  for (int i = index; (i < index + k) && (i < size); i++) {
    if (arr[i] < minValue) {
      minValue = arr[i];
      minKIndex = i;
    }
  }
  return minKIndex;
}

void swap(vector<int>& arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

vector <int> findMinArray(vector <int> arr, int k) {
  int size = (int) arr.size();
  if (size == 0) {
    return {};
  }
  if (k == 0) {
    return arr;
  }
  for (int i = 0; (i < size) && (k > 0); i++) {
    int minKIndex = getMinK(arr, i + 1, k, size);
    swap(arr, i, minKIndex);
    k--;
  }
  return arr;
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

  int n_1 = 3, k_1 = 2;
  vector <int> arr_1{5, 3, 1};
  vector <int> expected_1{1, 5, 3};
  vector <int> output_1 = findMinArray(arr_1,k_1);
  check(expected_1, output_1);

  int n_2 = 5, k_2 = 3;
  vector <int> arr_2{8, 9 ,11, 2, 1};
  vector <int> expected_2{2, 8, 9, 11, 1};
  vector <int> output_2 = findMinArray(arr_2,k_2);
  check(expected_2, output_2);
}
