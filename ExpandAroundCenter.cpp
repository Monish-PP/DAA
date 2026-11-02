#include<iostream>
#include<string>
using namespace std;
int start=0;
int maxlen=1;
void Expand(string s,int left,int right)
{
    while(left>=0 && right<s.length() && s[left]==s[right])
    {
        if(right-left-1>maxlen)
        {
            start=left+1;
            maxlen=right-left-1;
        }
    
        left--;
        right++;
    }
}
int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        Expand(s,i,i);
        Expand(s,i,i+1);
    }
    cout<<"Longest Palindromic Substring: "<<s.substr(start,maxlen);
    return 0;
}
