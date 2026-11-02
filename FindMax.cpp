#include <iostream>
#include <vector>
using namespace std;
int FindMaximum(vector<int>v)
{
    int large =v[0];
    for(int i=1;i<v.size();i++){
        if(large<v[i])
            large=v[i];
    }
    return large;
}
int main() {
    vector<int>V={12, 45, 7, 89, 34};
    cout<<"Maximum element: "<<FindMaximum(V);
    return 0;
}
