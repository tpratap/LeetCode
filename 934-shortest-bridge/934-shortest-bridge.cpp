class Solution {
public:
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    void dfs(vector<vector<int>>& grid, int i, int j, int n) {
        if(i >= n || j >= n || i < 0 || j < 0 || grid[i][j] != 1)
            return;
        grid[i][j] = 2;
        for(int k = 0; k < 4; ++k) {
            int x = i + dir[k][0];
            int y = j + dir[k][1];
            dfs(grid, x, y, n);
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n , INT_MAX));
        bool breaks = false;
        queue<pair<int,int>> q;
        for(int i = 0; i < n; ++i) { 
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1 && !breaks) {
                    dfs(grid, i, j, n);
                    breaks = true;
                } else if(grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int k =0 ; k < 4; ++k){
                int x = i + dir[k][0];
                int y = j + dir[k][1];
                if(x >= 0 && y >= 0 && x < n && y < n) {
                    if(dist[i][j] + 1 < dist[x][y]) {
                        if(grid[x][y] != 1){
                            dist[x][y] = 1 + dist[i][j];
                            q.push({x, y});
                        }
                    }
                }
            }
        }
        
        int res = INT_MAX;
        for(int i = 0; i <n; ++i){
            for(int j=0; j <n; ++j){
                if(grid[i][j] == 2)
                    res = min(res, dist[i][j]);
            }
        }
        return res-1;
    }
};