#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string text = "ABABCABCABABABD";
    string pattern = "ABABD";
    int m = pattern.length();
    int n = text.length();
    vector<int> v(m, 0);
    int len = 0;
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            v[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len =v[len - 1];
            }
            else {
                v[i] = 0;
                i++;
            }
        }
    }
    
    for (int x : v)
        cout << x << "\t";
    cout << endl;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = v[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == m) {
            cout << "Pattern found at index: " << i - m + 1 << endl;
            j = v[j - 1];
        }
    }
    return 0;
}