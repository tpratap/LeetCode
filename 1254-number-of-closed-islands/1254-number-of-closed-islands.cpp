class Solution {
public:
   
    int m,n;
    bool isClosed;
    void dfs(vector<vector<int>>& grid, int i, int j) {
        
        if(i < 0 || j < 0 || i >= m || j >= n) 
        {
            isClosed = false;
            return;
        }
        
        if(grid[i][j] == 1 || grid[i][j] == -1)
           return;

       if(grid[i][j] == 0)
           grid[i][j] = -1;
        
        dfs(grid, i+1, j);
        dfs(grid, i, j+1);
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int island = 0;
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    isClosed = true;
                    dfs(grid, i, j);
                    if(isClosed) {
                        island++;
                    }
                }
            }
        }
        return island;
    }
};