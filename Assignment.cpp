#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cout<<"Enter the no. of jobs/workers : ";
    cin>>n;
    vector<vector<int>> c(n,vector<int>(n));
    cout<<"Enter the cost matrix : \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>c[i][j];
        }
    }
    vector<int>p;
    for(int i=0;i<n;i++){
        p.push_back(i);
    }
    int minCost=INT_MAX;
    do{
        int cost=0;
        for(int i=0;i<n;i++){
            cost+=c[i][p[i]];
        }
        if(cost<minCost){
            minCost=cost;
        }
    }while(next_permutation(p.begin(),p.end()));
    cout<<"Minimum cost is : "<<minCost<<endl;
    return 0;
}   