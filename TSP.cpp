#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of cities : ";
    cin>>n;
    vector<vector<int>>c(n,vector<int>(n));
    cout<<"Enter the cost matrix : \n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>c[i][j];
    vector<int>p;
    for(int i=1;i<n;i++)
        p.push_back(i);
    int minCost=INT_MAX;
    do{
        int cost=0;
        int current=0;
        for(int x:p){
            cost+=c[current][x];
            current=x;
        }
        cost+=c[current][0];
        if(cost<minCost)
            minCost=cost;
    }while(next_permutation(p.begin(),p.end()));
    cout<<"Minimum Cost : "<<minCost<<endl;
    return 0;
}