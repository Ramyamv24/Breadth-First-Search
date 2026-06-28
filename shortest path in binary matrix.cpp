#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        q.push({{0, 0}, 1});
        vis[0][0] = 1;

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            if (r == n - 1 && c == n - 1)
                return dist;

            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    if (!vis[nr][nc] && grid[nr][nc] == 0) {
                        q.push({{nr, nc}, dist + 1});
                        vis[nr][nc] = 1;
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    int n;
    cout << "Enter size of grid: ";
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    cout << "Enter the grid (0 for open cell, 1 for blocked cell):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    int ans = obj.shortestPathBinaryMatrix(grid);

    cout << "Shortest Path Length: " << ans << endl;

    return 0;
}