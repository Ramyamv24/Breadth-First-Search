#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // DFS to sink all connected land cells
    void dfs(vector<vector<char>>& grid, int row, int col) {
        int m = grid.size();
        int n = grid[0].size();

        // Base case: out of bounds or water
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == '0')
            return;

        // Mark current cell as visited
        grid[row][col] = '0';

        // Visit all 4 directions
        dfs(grid, row + 1, col); // Down
        dfs(grid, row - 1, col); // Up
        dfs(grid, row, col + 1); // Right
        dfs(grid, row, col - 1); // Left
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islandCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islandCount++;
                    dfs(grid, i, j);
                }
            }
        }

        return islandCount;
    }
};

int main() {
    int m, n;

    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));

    cout << "Enter the grid (0 for water, 1 for land):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    int ans = obj.numIslands(grid);

    cout << "Number of Islands = " << ans << endl;

    return 0;
}