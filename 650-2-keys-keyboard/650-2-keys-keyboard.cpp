class Solution {
    int minCost(int n, int i, int prev, vector<vector<int>> &dp) {
        if(i == n)
            return 0;
        
        if(dp[i][prev] != -1)
            return dp[i][prev];
        
        int ch1 = INT_MAX, ch2 = INT_MAX;
        
        if(i*2 <= n) {
            int ret = minCost(n, i*2, i, dp); //Copy + Paste
            if(ret != INT_MAX)
                ch1 = ret + 2;
            else
                ch1 = INT_MAX;
        }
        
        if(prev != 0 && i+prev <= n) {
            int ret = minCost(n, i + prev, prev, dp); //Paste
            if(ret != INT_MAX)
                ch2 = ret + 1;
            else
                ch2 = INT_MAX;
        }
        return dp[i][prev] = min(ch1, ch2);
    }
public:
    int minSteps(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return minCost(n, 1, 0, dp);
    }
};