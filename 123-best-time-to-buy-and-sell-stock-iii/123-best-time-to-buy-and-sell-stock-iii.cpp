class Solution {
    vector<vector<vector<int>>> dp;
    int dfs(vector<int>& prices, int i, int trans, int bought) {
        if(i >= prices.size() || trans == 0)
            return dp[bought][trans][i] = 0;
        
        if(dp[bought][trans][i] != -1)
            return dp[bought][trans][i];
        
        int result = dfs(prices, i+1, trans, bought);
        
        if(bought == 1) {
            result = max(result, dfs(prices, i+1, trans-1, 0) + prices[i]);
        } else {
            result = max(result, dfs(prices, i+1, trans, 1) - prices[i]);
        }
        return dp[bought][trans][i] = result;
        
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(3, vector<vector<int>>(3, vector<int>(n+1, -1)));
        return dfs(prices, 0, 2, 0);
    }
};