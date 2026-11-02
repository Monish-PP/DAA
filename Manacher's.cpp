#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string manachersAlgorithm(string s) {
    string t="^";
    for(char c:s)
    {
        t+=c;
        t+="#";
    }
    t+="#$";
    int n=t.length();
    int p[n];
    int c=0,r=0;
    for(int i=1;i<n-1;i++)
    {
        int mirror=2*c-i;
        if(i<r)
        {
            p[i]=min(r-i,p[mirror]);
        }
        while(t[i+(1+p[i])]==t[i-(1+p[i])])
        {
            p[i]++;
        }
        if(i+p[i]>r)
        {
            c=i;
            r=i+p[i];
        }
    }
    int maxlen=0;
    int centerIndex=0;
    for(int i=1;i<n-1;i++)
    {
        if(p[i]>maxlen)
        {
            maxlen=p[i];
            centerIndex=i;
        }
    }
    int start =(centerIndex-maxlen)/2;
    return s.substr(start,maxlen);  
}
int main(){
    string s;
    cout<<"Enter the string : ";
    cin>>s;
    cout<<"Longest Palindromic Substring is : "<<manachersAlgorithm(s)<<endl;
    return 0;
}