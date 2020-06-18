using namespace std;

#define GREEDY

// Example 1:
// Input = [5, 10, 6, 8]
// Output = [5, 8, 10, 6]
// awkwardness = 4
//
// Example 2:
// Input = [1 2 5 3 7]
// Output = [1 3 7 5 2]
//
// awkwardness = 4
//
// Complexity: 
// - Permutations: Time = O(n! * n), Space = O(1);
// - Greedy: Time = O(n ^ 2), SPace = O(1)
//
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

int getMinIndex (vector<int>& arr, int left, int right) {
  int size = (int) arr.size();
  if (size == 0) {
    return -1;
  }
  int minIndex = left;
  int minValue = arr[left];
  for (int i = left; i <= right; i++) {
    if (arr[i] < minValue) {
      minValue = arr[i];
      minIndex = i;
    }
  }
  return minIndex;
}

void swap(vector<int>& arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}


int minOverallAwkwardness(vector <int> arr) {
#ifdef GREEDY
  // Greedy algorithm
  // 1. left = 0, right = size - 1; while (left < right)
  // 2. Find the minimum element between indexes left and right and swap with arr[left];
  // 3. Increment left
  // 4. Find the next minimum element between indexes left and right and swap with arr[right];
  // 5. Decrement right
  int size = (int) arr.size();
  if (size == 0) {
    return 0;
  }
  int left = 0;
  int right = size - 1;
  int minIndex;
  
  while (left < right) {
    minIndex = getMinIndex (arr, left, right);
    if (minIndex == -1) return -1;
    swap(arr, left, minIndex);
    left++;
    if (left < right) {
      minIndex = getMinIndex (arr, left, right);
      if (minIndex == -1) return -1;
      swap(arr, right, minIndex); 
      right--;
    }
  }
  return getAwkwardness(arr);
#endif
  
#ifdef BRUTE_FORCE  
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
#endif  
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
