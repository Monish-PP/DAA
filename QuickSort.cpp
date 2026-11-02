#include<iostream>
#include<vector>
using namespace std;

int Partition(vector<int>&v,int low,int high)
{
    int pivot = v[low];
    int i = low;
    int j = high;
    while(i < j)
    {
        while(i<=high && v[i]<=pivot)
            i++;

        while(v[j]>pivot)
            j--;

        if(i < j)
            swap(v[i], v[j]);
    }

    swap(v[low], v[j]);
    return j;   
}

void QuickSort(vector<int>&v,int low,int high)
{
    if(low < high)
    {
        int pi = Partition(v, low, high);
        QuickSort(v, low, pi - 1);
        QuickSort(v, pi + 1, high);
    }
}

int main()
{
    int n;

    cout<<"Enter the number of elements: ";
    cin>>n;

    vector<int> arr(n);

    cout<<"Enter the elements:\n";

    for(int i=0;i<n;i++)
        cin>>arr[i];

    QuickSort(arr,0,n-1);

    cout<<"Sorted array:\n";

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}