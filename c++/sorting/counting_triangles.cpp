#include <bits/stdc++.h>

// Example 1
// triangles = [[2, 2, 3], [3, 2, 2], [2, 5, 6]]
// output = 2
//
// Example 2
// triangles = [[8, 4, 6], [100, 101, 102], [84, 93, 173]]
// output = 3
//
// Example 3
// triangles = [[5, 8, 9], [5, 9, 8], [9, 5, 8], [9, 8, 5], [8, 9, 5], [8, 5, 9]]
// output = 1
//
// Complexity: Time = O(n log n), Space = O(1)

using namespace std;

struct sides{
  long long a;
  long long b;
  long long c;
};

void swap(long long& x, long long& y) {
  long long tmp = x;
  x = y;
  y = tmp;
}

int sortSideDecreasing(sides& s) {
  // Sort sides in decreasing order
  // vector<long long int> sData{s.a, s.b, s.c};
  // sort(sData.begin(), sData.end(), less<long long>());
  // s.a = sData[0];
  // s.b = sData[1];
  // s.c = sData[2];
  // Sorting three numbers in place
  if (s.a < s.b) swap(s.a, s.b);
  if (s.b < s.c) swap(s.b, s.c);
  if (s.a < s.b) swap(s.a, s.b);
}

int sidesLessThan(const sides& x, const sides& y) {
 // This functions assume decreasing order a, b, c
 return (x.a < y.a) ||
         (x.a == y.a && x.b < y.b) || 
         (x.a == y.a && x.b == y.b && x.c < y.c); 
}

bool sidesDifferent(const sides& x, const sides& y) {
  return (x.a != y.a || x.b != y.b || x.c != y.c);
}

int countDistinctTriangles(vector <sides> arr) {
  int n = (int) arr.size();
  if (n == 0) return 0;
  
  // Sort each triangle - O(n 3 log 3) = O(n)
  for (int i = 0; i < n; i++) {
    sortSideDecreasing(arr[i]);
  }
  
  // Sort listof triangles - O(n log n)
  sort(arr.begin(), arr.end(), sidesLessThan);
  
  int count = 1;
  for (int i = 1; i < n; i++) {
    if (sidesDifferent (arr[i], arr[i - 1])) {
      count++;
    }
  }
  
  return count;
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

  vector<sides> arr_1 = {{7, 6, 5}, {5, 7, 6}, {8, 2, 9}, {2, 3, 4}, {2, 4, 3}};
  int expected_1 = 3;
  int output_1 = countDistinctTriangles(arr_1);
  check(expected_1, output_1);

  vector<sides> arr_2 = {{3, 4, 5}, {8, 8, 9}, {7, 7, 7}};
  int expected_2 = 3;
  int output_2 = countDistinctTriangles(arr_2);
  check(expected_2, output_2);
}
