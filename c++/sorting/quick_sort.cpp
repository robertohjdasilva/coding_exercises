#include <bits/stdc++.h>
using namespace std;


void printArr(vector<int>& arr, int begin, int end) {
    for (int i = begin; i <= end; i++) {
        cout << arr[i];
        if (i < end) cout << " ";
    }
    cout << endl;
}

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// Execution: [5 8 1 3 7 9 2]
// pivot        down
//   |           |
//   3   2   1   5   7   9   8
//                   |
//                   up
int quickPartitionPivotFirst(vector <int> &arr, int left, int right) {
    int pivot = arr[left];
    int up = left + 1;
    int down = right;
    
    while (up <= down) {
        while (up <= down && arr[up] < pivot) up++;
        while (up <= down && arr[down] > pivot) down--;
        if (up <= down) swap(arr[up], arr[down]);
    }

    swap(arr[left], arr[down]);
    return down;
}

int quickPartitionPivotLast(vector <int> &arr, int left, int right) {
    int pivot = arr[right];
    int smallerIndex = left - 1; // Not 0 - 1, but left - 1
    
    // Pivot is the last element, so we only iterate until index 'right - 1'
    for (int i = left; i <= right - 1; i++) {
        if (arr[i] <= pivot) {
            smallerIndex++;
            swap(arr[smallerIndex], arr[i]);
        }
    }
    swap(arr[smallerIndex + 1], arr[right]);
    return smallerIndex + 1;
}

void quickSortInPlace(vector <int> &arr, int left, int right) {
    if (left >= right) {
        // '=' Note that an array with a single element is already sorted
        return;
    }
    int partitionIndex = quickPartitionPivotFirst(arr, left, right);
    quickSortInPlace(arr, left, partitionIndex - 1);
    quickSortInPlace(arr, partitionIndex + 1, right);
    printArr(arr, left, right);
}

int quickPartitionExtraSpace(vector <int> &arr, vector<int>& smallerPartition, vector<int>& greaterPartition) {
    int pivot = arr[0];

    for (int i = 0; i < (int) arr.size(); i++) {
        if(arr[i] < pivot) {
            smallerPartition.push_back(arr[i]);
        } else if(arr[i] > pivot) {
            greaterPartition.push_back(arr[i]);
        }
    }
    return (int) smallerPartition.size();
}

void quickSortExtraSpace(vector <int> &arr) {
    int size = (int) arr.size();
    if (size < 2) {
        // '=' Note that an array with a single element is already sorted
        return;
    }

    // Used as auxiliary arrays
    vector<int> smallerPartition, greaterPartition;

    int pivot = arr[0];

    int partitionIndex = quickPartitionExtraSpace(arr, smallerPartition, greaterPartition);
    
    quickSortExtraSpace(smallerPartition);
    quickSortExtraSpace(greaterPartition);

    // Copy content of each auxiliary vector holding the smaller
    // partitions to the original array
    for(int i = 0; i < (int) smallerPartition.size(); i++) {
        arr[i] = smallerPartition[i];
    }

    // Copy pivot
    arr[partitionIndex] = pivot;

    // Copy content of each auxiliary vector holding the greater
    // partitions to the original array
    for(int i = 0; i < (int) greaterPartition.size(); i++) {
      arr[partitionIndex + 1 + i] = greaterPartition[i];
    }

    printArr(arr, 0, (int) arr.size() - 1);
}

void quickSort(vector <int> &arr) {
    quickSortExtraSpace(arr);
}

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr);

    return 0;
}
