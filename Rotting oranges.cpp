#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh_oranges = 0;
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        // Count fresh oranges and store rotten oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    fresh_oranges++;
                else if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        int time = 0;

        // BFS
        while (!q.empty() && fresh_oranges > 0) {
            int sz = q.size();

            while (sz--) {
                pair<int, int> p = q.front();
                q.pop();

                int x = p.first;
                int y = p.second;

                // Up
                if (x - 1 >= 0 && grid[x - 1][y] == 1) {
                    grid[x - 1][y] = 2;
                    fresh_oranges--;
                    q.push({x - 1, y});
                }

                // Down
                if (x + 1 < n && grid[x + 1][y] == 1) {
                    grid[x + 1][y] = 2;
                    fresh_oranges--;
                    q.push({x + 1, y});
                }

                // Left
                if (y - 1 >= 0 && grid[x][y - 1] == 1) {
                    grid[x][y - 1] = 2;
                    fresh_oranges--;
                    q.push({x, y - 1});
                }

                // Right
                if (y + 1 < m && grid[x][y + 1] == 1) {
                    grid[x][y + 1] = 2;
                    fresh_oranges--;
                    q.push({x, y + 1});
                }
            }

            time++;
        }

        if (fresh_oranges == 0)
            return time;
        else
            return -1;
    }
};

int main() {
    int n, m;

    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    cout << "Enter the grid (0 = Empty, 1 = Fresh, 2 = Rotten):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    int ans = obj.orangesRotting(grid);

    cout << "Minimum time required: " << ans << endl;

    return 0;
}