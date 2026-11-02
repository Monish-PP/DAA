#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double fractionalKnapsack(int n,int w,vector<int>& weight,vector<int>& profit){
    vector<pair<double,int>> ratio(n);
    for(int i=0;i<n;i++)
        ratio[i]={(double)profit[i]/weight[i],i};
    sort(ratio.begin(),ratio.end(),greater<pair<double,int>>());
    double totalValue=0;
    for(int i=0;i<n;i++){
        int index=ratio[i].second;        
        if(weight[index]<=w){
            w-=weight[index];
            totalValue+=profit[index];
        }
        else{
            double fractional=(double)w/weight[index];
            totalValue+=fractional*profit[index];
            break;
        }
    }
    return totalValue;
}
int main(){
    int n,w;
    vector<int> weight,profit;

    cout<<"Enter the number of items:";
    cin>>n;
    cout<<"Enter the Weight of the Knapsack:";
    cin>>w;
    cout<<"Enter the weights of the items:\n";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        weight.push_back(x);
    }
    cout<<"Enter the profits of the items:\n";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        profit.push_back(x);
    }
    double maxProfit=fractionalKnapsack(n,w,weight,profit);
    cout<<"Maximum Profit: "<<maxProfit;
    return 0;
}