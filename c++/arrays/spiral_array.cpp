#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> getSpiralArray(int m, int n) {
    if (m < 1 || n < 1) return {};

    vector<vector<int>> arr(m, vector<int>(n));

    int count = 0;
    int startRow = 0, endRow = m - 1;
    int startCol = 0, endCol = n - 1;
    int row = 0, col = 0;
    
    // '||' condition just to handle cases in which the dimensions are not
    // the same.
    while (startRow <= endRow || startCol <= endCol) {
        // Top row: left -> right
        for (col = startCol; col <= endCol; col++) {
            arr[startRow][col] = ++count;
        }
        // Right column: top -> bottom
        for (row = startRow + 1; row <= endRow; row++) {
            arr[row][endCol] = ++count;
        }
        // Bottom row: right -> left
        if (startRow < endRow) {
            // Don't count the same row twice i.e. 
            // left to right and right to left.
            for (col = endCol - 1; col >= startCol; col--) {
                arr[endRow][col] = ++count;
            }
        }
        // Left column: bottom -> top
        if (startCol < endCol) {
            // Don't count the same colum twice i.e. 
            // top to bottom and bottom to top.
            for (row = endRow - 1; row > startRow; row--) {
                arr[row][startCol] = ++count;
            }
        }
        // Reduce perimeter
        startCol++; endCol--; startRow++; endRow--;
    }
    return arr;
}

void printSpiralArray (int m, int n) {
    cout << "Printing array: n = " << n << endl;
    cout << "==================================================\n";
    auto array = getSpiralArray (m, n);

    for (int i = 0; i < array.size(); i++) {
        for (int j = 0; j < array[0].size(); j++) {
            cout << setw(2) << array[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    cout << "Running tests!" << endl;

    for (int i = -1; i <= 6; i++) {
        printSpiralArray (i, i);
    }
    for (int i = -1; i <= 5; i++) {
        printSpiralArray (i, i + 1);
    }
    for (int i = -1; i <= 6; i++) {
        printSpiralArray (i, i - 1);
    }
    return 0;
}