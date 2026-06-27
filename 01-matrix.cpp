#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> DIR = {0, 1, 0, -1, 0};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;

        // Put all 0's into the queue and mark 1's as unvisited (-1)
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (mat[r][c] == 0)
                    q.emplace(r, c);
                else
                    mat[r][c] = -1;
            }
        }

        // Multi-Source BFS
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = r + DIR[i];
                int nc = c + DIR[i + 1];

                // Check boundaries and visit only unprocessed cells
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || mat[nr][nc] != -1)
                    continue;

                mat[nr][nc] = mat[r][c] + 1;
                q.emplace(nr, nc);
            }
        }

        return mat;
    }
};

int main() {
    int m, n;

    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));

    cout << "Enter the matrix (only 0 and 1):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    Solution obj;
    vector<vector<int>> ans = obj.updateMatrix(mat);

    cout << "\nUpdated Matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}