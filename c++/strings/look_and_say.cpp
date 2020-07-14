// 1
// 11
// 21
// 1211
// 111221
// 312211
// 13112221
// 1113213211
// 31131211131221
// 13211311123113112211

#include <bits/stdc++.h>

using namespace std;

string integer2String (int count) {
    string str;
    ostringstream ss;
    ss << count;
    return ss.str();
}

string getNextSeqStr(string& str) {
    string nextStr;
    int len = (int) str.length();
    int nextStrIdx = 0;
    int idx = 0;

    while (idx < len) {
        char ch = str[idx++];
        int count = 1;
        while (idx < len && str[idx] == ch) {
            count++;
            idx++;
        }
        nextStr += integer2String (count) + ch;
    }

    return nextStr;
}

string getLookAndSay (int n) {
    if (n == 0) return "";
    if (n == 1) return "1";
    string str = "1";
    for (int i = 1; i < n; i++) {
        str = getNextSeqStr(str);
    }
    return str;
}

int main() {
    cout << "Running tests!" << endl;

    for (int i = 0; i <= 10; i++) {
        cout << "n = " << i << " => processing..." << endl;
        cout << getLookAndSay (i) << endl;
    }
    return 0;
}