#include<iostream>
#include<string>
using namespace std;
int main() {
    string text = "ABABCABCABABABD";
    string pattern = "ABABD";
    int n = text.length();
    int m = pattern.length();
    int d = 256;
    int q = 101;
    int pHash = 0;
    int tHash = 0;
    int h = 1;
    int count = 0;
    cout<<"pattern weight \n";
    int s1=1;
    for(int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }
    cout<<"windows\n";
    for(int i = 0; i < m; i++) {
        pHash = (d * pHash + pattern[i]) % q;
        tHash = (d * tHash + text[i]) % q;
    }

        cout<<"pattern hash "<<pHash<<"\t"<<endl;
        cout<<"window "<<s1++<<"\t";
        cout<<tHash<<endl;
    for(int i = 0; i <= n - m; i++) {
        if(pHash == tHash) {
            bool match = true;
            for(int j = 0; j < m; j++) {
                if(text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if(match) {
                cout << "Pattern found at index: " << i << endl;
                count++;
            }
        }
        if(i < n - m) {
            tHash = (d * (tHash - text[i] * h) + text[i + m]) % q;
            if(tHash < 0) {
                tHash += q;
            }
            cout<<"window "<<s1++<<"\t"<<tHash<<endl;
        }
    }
    cout << "Total patterns found: " << count << endl;
    return 0;
}