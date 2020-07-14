#include <bits/stdc++.h>

using namespace std;

void swap (string **pp1, string **pp2) {
    string *tmp = *pp1;
    *pp1 = *pp2;
    *pp2 = tmp;
}

// Complexity: Time = O(n), Space= O(1)
bool oneEditApart (string* s1, string* s2) {
    int len1 = s1 != NULL ? (int) s1->length() : -1;
    int len2 = s2 != NULL ? (int) s2->length() : -1;
    if (abs(len1 - len2) > 1) {
        return false;
    }
    // Make s1 shorter
    if (len1 > len2) swap(s1, s1);
    bool diff = false;
    for (int i = 0, j = 0; i < s1->length(); i++, j++) {
        if ((*s1)[i] != (*s2)[j]) {
            if (diff == true) {
                // Second difference!
                return false;
            }
            diff = true;
            if (len1 != len2) {
                i--; // casa, xcasa -> Move 'j', but not 'i'
            }
        }
    }
    // Case 1: Same length and diff is true
    // Case 2: s2 longer and diff is obviously true
    return diff || (len1 != len2);
}

int main() {
    cout << "Running tests!" << endl;
    vector<string> s1{"", "",  "test",  "casa",  "test", "cat"};
    vector<string> s2{"", "a", "testa", "xcasa", "text", "cat"};

    for (int i = 0; i < s1.size(); i++) {
        cout << "Check: " << setw(6) << s1[i] << ", " << setw(6) << s2[i] << " => " 
            << oneEditApart (&s1[i], &s2[i]) << endl;
    }

    return 0;
}