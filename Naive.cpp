#include<iostream>
using namespace std;
int main(){
string text,pattern;
cout<<"Enter the text : ";
cin>>text;
cout<<"Enter the pattern : ";
cin>>pattern;
int c=0;
int n=text.length();
int m=pattern.length();
int j=0;
for(int i=0;i<=n-m;++i){
    for(j=0;j<m;++j){
        if(text[i+j]!=pattern[j]){
            break;
        }
    }
    if(j==m){
            cout<<"Pattern found at index : "<<i<<endl;
            ++c;
        }
}
cout<<"Total pattern found : "<<c<<endl;
return 0;
}