#include <bits/stdc++.h>

using namespace std;

// Complexity: Time = O(n), Space = O(n)
// 
// Execution: 
// arr = {1, 3, 4, 5, 6}, m = 6
//
//  costMap
//  key/cost value/index
//  1       1
//  3       2
//  4       3
//
// result: {1, 4}
vector<int> icecreamParlor(int m, vector<int> arr) {
    unordered_map<int, int> costMap; // key = cost, value = 1-based index
    if (arr.size() == 0 || m <= 0) return {};

    for (int i = 0; i < (int) arr.size(); i++) {
        int costComplement = m - arr[i];
        auto it = costMap.find (costComplement);
        if (it != costMap.end()) {
            vector<int> costList{it->second, i + 1};
            sort(costList.begin(), costList.end());
            return costList;
        } else {
            costMap[arr[i]]= i + 1;
        }
    }
    return {};
}
