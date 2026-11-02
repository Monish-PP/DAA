#include<iostream>
using namespace std;
int a=0,b=1,sum=0,v=0;
void  fibonacci(int k){
    if(k==0)return;
sum=a+b;
a=b;
b=sum;
cout<<b<<"\t";
fibonacci(--k);
}
int main(){

cout<<"Enter the number of elements to printed in the fibonacci series : ";
cin>>v;
 if(v <= 0)
    {
        cout << "Invalid input";
    }
    else if(v == 1)
    {
        cout << 0;
    }
    else
    {
        cout << 0 << "\t" << 1 << "\t";
        fibonacci(v - 2);
    }
}