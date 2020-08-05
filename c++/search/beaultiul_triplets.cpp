#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Example: {2, 2, 3, 4, 5}, d = 1
// Definition: arr[j] - arr[i] = arr[k]- arr[j] = d
int beautifulTriplets(int d, vector<int> arr) {
    int size = (int) arr.size();
    if (size < 3) {
        return 0;
    }
    int count = 0;
    
    // O(n ^ 3) - worst, O(n ^ 2) - average, Space = O(1)
    for (int i = 0; i < size - 2; i++) {
        for (int j = i + 1; j < size - 1; j++) {
            if (arr[j] - arr[i] == d) { // Holy Grail to save time!
                for (int k = j + 1; k < size; k++) {
                    if (d == arr[k] - arr[j]) {
                        count++;
                    }
                }
            }
        }
    }

    /* Optimized solution in O(n ^ 2), Space = O(1)
    //
    // Execution:
    // d = 1
    //        *
    //  i     l  r
    //  |     |  |
    // [2, 2, 3, 4, 5]
    for (int i = 0; i < size - 2; i++) {
        int left = i + 1;
        int right = size - 1;
        bool leftCheck = false, rightCheck = false;
        while (left < right) {
            if (arr[left] - arr[i] < d) left++;
            else if (arr[left] - arr[i] > d) break;
            else leftCheck = true;

            if (arr[right] - arr[left] < d) break;
            else if (arr[right] - arr[left] > d) right--;
            else rightCheck = true;

            if (leftCheck && rightCheck) {
                count++;
                leftCheck = false;
                rightCheck = false;
                if ((left + 1 < size) && (arr[left + 1] == arr[left])) {
                    left++;
                } else if ((right - 1 > i) && (arr[right - 1] == arr[right])) {
                    right--;
                } else {
                    break;
                }
            }
        }
    }*/

    return count;
}

