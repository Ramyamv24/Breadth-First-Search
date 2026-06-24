#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp{0};

        while (dp.size() <= n) {
            int m = dp.size();
            int squares = INT_MAX;

            for (int i = 1; i * i <= m; ++i) {
                squares = min(squares, dp[m - i * i] + 1);
            }

            dp.push_back(squares);
        }

        return dp[n];
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Minimum number of perfect squares = "
         << sol.numSquares(n) << endl;

    return 0;
}