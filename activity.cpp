#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int finish;
};

void maxs(vector<Activity> & ac) {
    sort(ac.begin(), ac.end(), [](Activity & a, Activity & b) {
        return a.finish < b.finish;
    });

    Activity last = ac[0];
    cout<<"Activities that can be performed is : "<<endl;
    cout<<"(" << last.start << ", " << last.finish << ")" << endl;
    int count = 1;
 
    for(int i = 1; i < ac.size(); ++ i) {
        if(ac[i].start >= last.finish) {
            last = ac[i];
            count++;
            cout<<"(" << ac[i].start << ", " << ac[i].finish << ")" << endl;
        }
    }
    cout<<"Total number of activities that can be performed is : "<<endl;
    cout<< count << endl;
}

int main(void) {
    vector<Activity> activities = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    maxs(activities);
    return 0;
}