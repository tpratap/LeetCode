class Solution {
public:
    bool recur(string &s, string &t, int m, int n, vector<vector<bool>>& dp) {
        if(m > n)
            return dp[m][n] = false;
        
        if(m == 0 || n == 0)
            return dp[m][n] = true;
        
        if(dp[m][n] != false)
            return true;
        
        if(s[m-1] == t[n-1]) {
            return dp[m][n] = recur(s,t,m-1,n-1, dp);
        }
        return dp[m][n] =  recur(s,t,m,n-1, dp);
    }
    bool isSubsequence(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        return recur(s,t,m,n, dp);
    }
};