// Sample Input 0
// s = hackerhappy
// t = hackerrank
// k = 9
// Sample Output 0
// Yes
//
// Sample Input 1
// s = aba
// t = aba
// k = 7
// Sample Output 1
// Yes
//
// Sample Input 2
// s = ashley
// t = ash
// k = 2
// Sample Output 2
// No

#include <bits/stdc++.h>

using namespace std;

// Complexity
// Time = O(n), Space = O(1)
string appendAndDelete(string s, string t, int k) {
    int sLen = (int) s.length();
    int tLen = (int) t.length();

    // If s.length() + t.length() <= k: We can delete s completely and re-construct t
    if ((sLen + tLen) <= k) {
        return "Yes"; 
    }

    // Determine common length
    int commonLen = 0;
    int minLen = min (sLen, tLen);
    for (int i = 0; i < minLen; i++) {
        if (s[i] == t[i]) commonLen++;
        else break;
    }

    // If [k - (s.length() - common.length() + t.length - common.length())] is even,
    // then we can easily construct t from s. 
    // This is so because s.length() - common.length() is number of letters to 
    // be deleted and t.length() - common.length() is number of letters to be
    // added in s after deletion of the mismatching letters.
    // After this if the nmber of operations left is even, then we can add and remove
    // any random letter, which will cost an even number of operations.
    int numLettersToDeleteFromS = sLen - commonLen;
    int numLettersToAddToT = tLen - commonLen;
    int numOperations = k - numLettersToDeleteFromS -  numLettersToAddToT;
    if ((numOperations >= 0) && (numOperations % 2) == 0) {
        return "Yes";
    }

    // For all other cases, it is not possible to construct t from s.
    return "No";
}
