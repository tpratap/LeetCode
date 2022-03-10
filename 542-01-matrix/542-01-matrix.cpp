class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int k = 0; k < 4; ++k) {
                int x = i + dir[k][0];
                int y = j + dir[k][1];
                if(x >= 0 && y >= 0 && x < m && y < n) {
                    if(grid[x][y] == 1) {
                        grid[x][y] = 2;
                        dist[x][y] = dist[i][j] + 1;
                        q.push({x, y});
                    }
                } 
            }
        }
        return dist;
    }
};