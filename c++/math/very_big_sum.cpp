#include <bits/stdc++.h>

using namespace std;

long aVeryBigSum(vector<long> ar) {
    long long int sum = 0;
    for (const int num : ar) {
        sum += num;
    }
    return sum;
}