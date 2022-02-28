class Solution {
    int m, n;
    int dir[4][2] = {{0,-1}, {0, 1}, {-1, 0}, {1, 0}};
    vector<vector<int>> dp;
    bool isSafe(vector<vector<int>>& matrix, int i, int j) {
        if(i < 0 || j < 0 || i >= m || j >= n)
            return false;
        return true;
    }
public:
    int dfs(vector<vector<int>>& matrix, int i, int j) {

        if(dp[i][j] != -1)
            return dp[i][j];
        
        
        int ans = 0;
        
        for(int k = 0; k < 4; k++) {
            int x = i + dir[k][0];
            int y = j + dir[k][1];
            if(isSafe(matrix, x , y) && (matrix[i][j] < matrix[x][y])) {
                ans = max(ans, 1 + dfs(matrix, x, y));    
            }
        }
        
        return dp[i][j] = ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int ans = 0;
        
        dp.assign(m, vector<int>(n, -1));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
               // vector<vector<bool>> visited(m, vector<bool>(n, false));
                ans = max(ans, 1 + dfs(matrix, i, j));
            }
        }
        return ans;
    }
};