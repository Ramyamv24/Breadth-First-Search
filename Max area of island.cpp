#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0, n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m));
        vector<int> dy{-1, 1, 0, 0};
        vector<int> dx{0, 0, -1, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] && !visited[i][j]) {
                    int currentArea = 1;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;

                    while (!q.empty()) {
                        auto [y, x] = q.front();
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int ny = y + dy[k];
                            int nx = x + dx[k];

                            if (ny >= 0 && ny < n &&
                                nx >= 0 && nx < m &&
                                !visited[ny][nx] &&
                                grid[ny][nx]) {

                                q.push({ny, nx});
                                visited[ny][nx] = true;
                                currentArea++;
                            }
                        }
                    }

                    maxArea = max(maxArea, currentArea);
                }
            }
        }

        return maxArea;
    }
};

int main() {
    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    cout << "Enter the grid (0 for water, 1 for land):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    cout << "Maximum Area of Island: " << obj.maxAreaOfIsland(grid) << endl;

    return 0;
}