class Solution {
public:
    int solve(vector<int>& squares, int target, int n, vector<vector<int>> &dp) {
        if(target == 0) {
            return 0;
        }
        
        if(target < 0)
            return INT_MAX;
        
        if(n == 0)
            return INT_MAX;
        
        if(dp[target][n] != INT_MAX)
            return dp[target][n];
        
        int ans = INT_MAX;
        
        int include = solve(squares, target - squares[n-1], n-1, dp);
        int incexc = solve(squares, target - squares[n-1], n, dp);
        if(include != INT_MAX)
            include = include + 1;
        if(incexc != INT_MAX)
            incexc = incexc + 1;
        int exclude = solve(squares, target, n-1, dp);
        ans = min(include, min(exclude, incexc));
            
        
        return dp[target][n] = ans;
        
    }
    
    int numSquares(int n) {
        vector<int> squares;
        int i;
        for(i = 1; i*i <= n; ++i) {
            squares.push_back(i*i);
        }
        vector<vector<int>> dp(n+1, vector<int>(i+1, INT_MAX));
        return solve(squares, n, squares.size(), dp);
    }
};