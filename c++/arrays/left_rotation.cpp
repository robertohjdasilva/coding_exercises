#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<int> rotLeft(vector<int> a, int d) {
    int size = (int) a.size();
    if (size < 2) return a;
    vector<int> result(size);
    for (int dstIdx = 0; dstIdx < size; dstIdx++) {
        int srcIdx = (dstIdx + d) % size;
        result[dstIdx] = a[srcIdx];
    }
    return result;
}