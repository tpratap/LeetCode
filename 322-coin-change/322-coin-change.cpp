class Solution {
public:
    vector<vector<int>> dp;
    int minCoins(vector<int> &coins, int amount, int n){
        if(n == 0) 
            return INT_MAX;
        
        if(amount == 0) 
            return 0;
        
        if(dp[amount][n] != -1) 
            return dp[amount][n];
        
        if(coins[n-1] <= amount){
            int include =  minCoins(coins, amount- coins[n-1], n) ;
            int exclude =  minCoins(coins, amount, n - 1);
            if(include != INT_MAX) include = 1 + include;
            return dp[amount][n] = min(include, exclude);
        }
        else 
            return dp[amount][n] = minCoins(coins, amount, n - 1);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.assign(amount+1 ,vector<int>(n + 1, -1));
        int res = minCoins(coins, amount, n);
        if(res == INT_MAX) 
            return -1;
        return res ;
    }
};