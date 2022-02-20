class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited, int &count) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || visited[i][j] || grid[i][j] != 1)
            return;
        
        visited[i][j] = true;
        count++;
        
        dfs(grid, i-1, j, visited, count);  //up
        dfs(grid, i+1, j, visited, count);  //down
        dfs(grid, i, j-1, visited, count);  //left
        dfs(grid, i, j+1, visited, count);  //right
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count, maxArea = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    count = 0;
                    dfs(grid,i,j,visited,count);
                    maxArea = max(count, maxArea);
                }
            }
        }
        return maxArea;
    }
};