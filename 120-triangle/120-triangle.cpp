class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = triangle[0][0];
        for(int i = 1; i < n; ++i) {
            int val = 0;
            for(int j = 0; j <= i; ++j) {
                int newval;
                if(j == 0) {
                    newval = dp[j];
                    dp[j] = triangle[i][j] + dp[j];
                }
                else if(j == i) {
                    //newval = dp[j];
                    dp[j] = triangle[i][j] + val;
                }
                else {
                    newval = dp[j];
                    dp[j] = triangle[i][j] + min(dp[j] , val);
                }
                val = newval;
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; ++i)
            ans = min(ans, dp[i]);
        
        return ans;
    }
};