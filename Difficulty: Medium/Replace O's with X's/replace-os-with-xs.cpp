class Solution {
public:
    void fill(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 'O') q.push({i, 0});
            if (grid[i][m - 1] == 'O') q.push({i, m - 1});
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 'O') q.push({0, j});
            if (grid[n - 1][j] == 'O') q.push({n - 1, j});
        }
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] != 'O') continue;
            grid[x][y] = '#';
            q.push({x+1, y}); q.push({x-1, y}); q.push({x, y+1}); q.push({x, y-1});
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'O') grid[i][j] = 'X';
                else if (grid[i][j] == '#') grid[i][j] = 'O';
            }
        }
    }
};