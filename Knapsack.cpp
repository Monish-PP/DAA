#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of items : ";
    cin>>n;
    int weight[n],profit[n];
    cout<<"Enter Weights: ";
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    cout<<"Enter Profits: ";
    for(int i=0;i<n;i++){
        cin>>profit[i];
    }
    int capacity;
    cout<<"Enter capacity: ";
    cin>>capacity;
    int maxProfit=0;
    for(int mask=0;mask<(1<<n);mask++){
        int totalWeight=0,totalProfit=0;
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                totalWeight+=weight[i];
                totalProfit+=profit[i];
            }
        }
        if(totalWeight<=capacity&&totalProfit>maxProfit)
            maxProfit=totalProfit;
    }
    cout<<"Maximum Profit : "<<maxProfit<<endl;
    return 0;
}