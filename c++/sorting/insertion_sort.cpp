#include <bits/stdc++.h>

using namespace std;

void insertionSort(int n, vector<int> arr) {
    
    for (int unsortedStart = 1; unsortedStart < arr.size(); unsortedStart++) {
        int insertElement = arr[unsortedStart];
        int sortedIndex = unsortedStart - 1;

        while (sortedIndex >= 0 && arr[sortedIndex] > insertElement) {
            arr[sortedIndex + 1] = arr[sortedIndex];
            sortedIndex --;
        }
        arr[sortedIndex + 1] = insertElement;
    }
}
