class Solution {
    int m, n;
    int dfs(vector<vector<int>>&grid, int i, int j, vector<vector<int>> &dp) {
        if(i >= m || j >= n || grid[i][j] == 1)
            return 0;
        
        if(i == m-1 && j == n-1) {
            return 1;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int down = dfs(grid, i+1, j, dp);
        
        int right = dfs(grid, i, j+1, dp);
        
        return dp[i][j] = down + right;
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
                               
        return dfs(obstacleGrid, 0, 0, dp);
    }
};