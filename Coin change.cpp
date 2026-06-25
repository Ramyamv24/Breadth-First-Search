#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int solve(int ind, vector<int>& coins, int amount, int &n,
              vector<vector<int>> &dp) {
        if (amount == 0) {
            return 0;
        }

        if (ind == n || amount < 0) {
            return INT_MAX;
        }

        if (dp[ind][amount] != -1) {
            return dp[ind][amount];
        }

        int take = INT_MAX;
        int res = solve(ind, coins, amount - coins[ind], n, dp);

        if (res != INT_MAX) {
            take = 1 + res;
        }

        int nottake = solve(ind + 1, coins, amount, n, dp);

        return dp[ind][amount] = min(take, nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int ind = 0;
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = solve(ind, coins, amount, n, dp);

        if (ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int result = sol.coinChange(coins, amount);

    cout << "Coins: ";
    for (int coin : coins) {
        cout << coin << " ";
    }
    cout << "\nAmount: " << amount << endl;

    cout << "Minimum coins required: " << result << endl;

    return 0;
}