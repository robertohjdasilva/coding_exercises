#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here
// Example 1:
// Input: arr = [5, 15, 1, 3]
// Sort each subarray.
// Output: result = [5, 10, 5, 4]
// Careful with overflow!
//

vector <int> findMedian(vector <int> arr) {
  // Optimized: using max heap
  // Complexity: Time = O(n log n), Space = O(n)
  int size = (int) arr.size();
  if (size == 0) return {};
  
  vector<int> result;
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;

  // Even elements
  // maxHeap | minHeap
  // 1     3 | 5    15
  //       ^   ^
  //       |   |
  //     left  right
  //
  // Odd elements
  // maxHeap | minHeap
  // 1     5    15
  //       ^ 
  //       | 
  //     median
  
  int lastMedian;
  for (int i = 0; i < size; i++) { // O(n)
    // Always add first element to maxHeap.
    int num = arr[i];
    if (i == 0) {
      maxHeap.push(num); // O(log n)
      lastMedian = num;
    } else {
      // Add element to heaps
      if (num >= lastMedian) {
        minHeap.push (num); // O(log n)
      } else {
        maxHeap.push (num); // O(log n)
      }
      // If one heap has more than 1 element compared to the other, re-balance
      // We always try to keep the maxHeap with more elements
      int diff = maxHeap.size() - minHeap.size();
      if (abs(diff) > 1 || diff < 0) {
        if (diff > 0) {
          minHeap.push(maxHeap.top()); // maxHeap has too many elements, move top to minHeap
          maxHeap.pop();
        } else {
          maxHeap.push(minHeap.top()); // minHeap has too many elements, move top to maxHeap
          minHeap.pop();          
        }
      }
      
      // Determine median
      if ((maxHeap.size() + minHeap.size()) % 2) {
        lastMedian = maxHeap.top(); // Odd
      } else {
        lastMedian = (maxHeap.top() + minHeap.top())/2; // Even
      }
    }
    result.push_back(lastMedian);
  }  
  return result;
}

inline int getMedian (vector<int>& arr, int startIndex, int endIndex) {
  if (arr.size() < 1) return -1;
  int size = endIndex - startIndex + 1;
  
  // [1, 5, 15], size = 3
  if (size % 2) {
    // Odd
    return arr[size/2 + startIndex];
  } else {
    // Even
    int leftNum = size/2 - 1; // 0
    int rightNum = size/2; // 1
    long int median = arr[leftNum + startIndex] + arr[rightNum + startIndex];
    return (int) median/2;
  }
}
vector <int> findMedianNaive(vector <int> arr) {
  // Naive solution: Complexity: Time = O(n ^ 2 log n), Space = O(n)
  int size = (int) arr.size();
  if (size == 0) return {};
  
  vector<int> result;
  
  for (int i = 0; i < size; i++) {
    int median;
    int startIndex = 0, endIndex = i;    
    // sort takes the elemet past the last in the range
    sort (arr.begin(), arr.begin() + endIndex - startIndex + 1);
    median = getMedian (arr, startIndex, endIndex);
    result.push_back(median);
  }
  
  return result;
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
  vector <int> arr_1{5, 15, 1, 3};
  vector <int> expected_1{5, 10, 5, 4};
  vector <int> output_1 = findMedian(arr_1);
  check(expected_1, output_1);

  vector <int> arr_2{2, 4, 7, 1, 5, 3};
  vector <int> expected_2{2, 3, 4, 3, 4, 3};
  vector <int> output_2 = findMedian(arr_2);
  check(expected_2, output_2); 
}
