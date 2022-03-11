class Solution {
    int m, n;
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>&grid, int i, int j) {
        // if(i >= m || j >= n || grid[i][j] == 1) {
        //     cout<<"Not Feasible \n";
        //     return 0;
        // }
        
        if(i == m-1 && j == n-1) {
            //cout<<"Feasible \n";
            return 1;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int right = 0, down = 0;
        
        if(i+1 < m && grid[i+1][j] == 0) {
            //cout<<down<<"->";
            down = dfs(grid, i+1, j);
        }
        
        if(j+1 < n && grid[i][j+1] == 0) {
            //cout<<right<<"->";
            right = dfs(grid, i, j+1);
        }
        
        return dp[i][j] = down + right;
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;
        dp.assign(m+1, vector<int>(n+1, -1));
        return dfs(obstacleGrid, 0, 0);
    }
};