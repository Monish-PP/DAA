#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCoins(const vector<int>& coinDenominations, int targetAmount) {
    vector<int> minCoinsForAmount(targetAmount + 1, targetAmount + 1);
    minCoinsForAmount[0] = 0;

    for (int amount = 1; amount <= targetAmount; ++amount) {
        for (int coin : coinDenominations) {
            if (amount - coin >= 0) {
                minCoinsForAmount[amount] = min(
                    minCoinsForAmount[amount],
                    1 + minCoinsForAmount[amount - coin]
                );
            }
        }
    }

    return (minCoinsForAmount[targetAmount] > targetAmount) ? -1 : minCoinsForAmount[targetAmount];
}

int main() {
    vector<int> coinDenominations = {1, 2, 5};
    int targetAmount = 11;

    cout << "Min coins for " << targetAmount << ": "
         << minCoins(coinDenominations, targetAmount) << endl;

    return 0;
}