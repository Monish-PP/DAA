#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getNthUglyNumber(int n) {
    if (n <= 0) return 0;

  
    vector<int> dp(n);
    dp[0] = 1;
   
    int i2 = 0, i3 = 0, i5 = 0;

    for (int i = 1; i < n; ++i) {
       
        int next_mul_2 = dp[i2] * 2;
        int next_mul_3 = dp[i3] * 3;
        int next_mul_5 = dp[i5] * 5;

      
        int next_ugly = min({next_mul_2, next_mul_3, next_mul_5});
        dp[i] = next_ugly;

       
        if (next_ugly == next_mul_2) i2++;
        if (next_ugly == next_mul_3) i3++;
        if (next_ugly == next_mul_5) i5++;
    }

    return dp[n - 1]; 
}

int main() {
    int n = 10;
    cout << "The " << n << "th Ugly Number is: " << getNthUglyNumber(n) << endl;
    return 0;
}