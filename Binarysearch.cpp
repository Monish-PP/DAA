#include<iostream>
#include<vector>
using namespace std;
int binary_search(vector<int>v, int i,int j, int n) {
    if(i>j)
    return -1;
    int mid=(i+j)/2;
    if (v[mid]==n)
    return mid;
    else{
    if(v[mid]<n){
        return binary_search(v,mid+1,j,n);
    }
    else if(v[mid]>n){
        return binary_search(v,i,mid-1,n);
    }
    
    }
}   
int main(){
    vector <int>v(6);
    cout<<"Enter the elements of the array : ";
    for(int i=0;i<v.size();i++)
    {
        cin>>v[i];
    }
    int key;
    cout<<"Enter the element to search: ";
    cin>>key;
    int result = binary_search(v,0,v.size()-1,key);
    if(result == -1)
    cout<<"Element not found"<<endl;
    else
    cout<<"Found at index : "<<result<<endl;
    return 0;
}