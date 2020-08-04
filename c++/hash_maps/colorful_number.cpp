#include <bits/stdc++.h>

using namespace std;

// Examples:
// 3245 is colorful: 3 2 4 5 32 34 35 24 25 45 324 325 245 3245
// 326 is not colorful: 3 2 6 32 36 26 326
//
// Approach
// 1. Create a powerset of digits except empty set (Power Set)
// 2. Multiply all the digits in the individual powersets and insert into Hash Table.
// 3. If any point, number already present in the Hash table, return false
void getPowerSetsHelper(string& strNum, int runningIndex, string runningStr, vector<string>& powerSets) {
    if (runningIndex == strNum.length()) {
        if (runningStr != "") {
            // Add all power sets, except empty set
            powerSets.push_back(runningStr);
        }
        return;
    }
    getPowerSetsHelper(strNum, runningIndex + 1, runningStr, powerSets);
    getPowerSetsHelper(strNum, runningIndex + 1, runningStr + strNum[runningIndex], powerSets);

    // Execution
    // {strNum = "326"}
    //
    //                                      0, ""
    //                                /                    \
    //                             1, ""                 1, "3"
    //                           /       \             /          \
    //                         2, ""    2, "2"        2, "3"      2, "32"
    //                       /   \      /   \        /    \       /       \
    //                     3,"" 3,"6" 3,"2" 3,"26"  3,"3" 3,"36" 3,"32" 3,"326"
    //                    
}

string numToStr(int num) {
    stringstream oss;
    oss << num;
    return oss.str();
}

void getPowerSets(int num, vector<string>& powerSets) {
    string strNum = numToStr(num);
    getPowerSetsHelper(strNum, 0, "", powerSets);
}

long long int getProduct(string& str) {
    int size = (int) str.length();
    if (size == 0) return 0;
    int product = 1;

    for (int i = 0; i < size; i++) {
        product *= (long long int) (str[i] - '0');
    }
    return product;
}

bool isColorfulNumber(int num) {
    if (num < 0) return false;
    vector<string> powerSets;
    unordered_set<long long int> prodSet;

    getPowerSets(num, powerSets);

    for (string& powerSet : powerSets) {
        long long int prod = getProduct(powerSet);
        if (prodSet.find(prod) != prodSet.end()) {
            return false;
        } else {
            prodSet.insert(prod);
        }
    }
    return true;
}

int main () {
    cout << "3245 " << (isColorfulNumber(3245) ? "is" : "is not") << " a color number" << endl;
    cout << "326 " << (isColorfulNumber(326) ? "is" : "is not") << " a color number" << endl;
    return 0;
}