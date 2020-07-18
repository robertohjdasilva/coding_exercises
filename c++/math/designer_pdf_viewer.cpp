#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int designerPdfViewer(vector<int> h, string word) {
    int base = word.length ();
    int maxHeight = 0;
    for (char ch : word) {
        if (ch < 'a' || ch > 'z') assert (0);
        int currHeight = h[ch - 'a'];
        maxHeight = max (maxHeight, currHeight);
    }
    return (base * maxHeight);
}