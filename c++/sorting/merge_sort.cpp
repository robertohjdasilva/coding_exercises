#include <iostream>
#include <queue>

using namespace std;

void printArray(vector<int>& arr, const string& desc) {
    cout << "Array " << desc << ": {";
    int count = 0;
    for (int num : arr) {
        if (count++ > 0) cout << ", ";
        cout << num;
    }
    cout << "}" << endl;
}

void mergeCombine(vector<int>& arr, int leftStart, int rightEnd) {
    vector<int> combineArr(rightEnd - leftStart + 1);
    int mid = leftStart + (rightEnd - leftStart)/2;
    int leftEnd = mid; 
    int rightStart = mid + 1;
    int left = leftStart;
    int right = rightStart;
    int idxCombine = 0;
        
    while (left <= leftEnd && right <= rightEnd) {
        if (arr[left] <= arr[right]) {
            combineArr[idxCombine++] = arr[left++];
        } else {
            combineArr[idxCombine++] = arr[right++];
        }
    }

    // leftStart     leftEnd  rightStart right  rightEnd
    while (left <= leftEnd) {
        combineArr[idxCombine++] = arr[left++];
    }
    while (right <= rightEnd) {
        combineArr[idxCombine++] = arr[right++];
    }
    copy(combineArr.begin(), combineArr.end(), arr.begin() + leftStart);    
}

void mergeSort(vector<int>& arr, int leftStart, int rightEnd) {
    if (leftStart >= rightEnd) {
        return;
    }
    int mid = leftStart + (rightEnd - leftStart)/2;
    mergeSort(arr, leftStart, mid);
    mergeSort(arr, mid + 1, rightEnd);
    mergeCombine(arr, leftStart, rightEnd);
}

void mergeSort (vector<int>& arr) {
    mergeSort(arr, 0, (int) arr.size() - 1);
}

int main() {
    cout << "Running tests!" << endl;

    vector<int> arr{1, 3, 6, 2, 4, -3, 12, 3, 5, 21, 32, 17, 8, 11};

    printArray (arr, "before sorting");
    mergeSort(arr);
    printArray (arr, "after sorting");

    return 0;
}
