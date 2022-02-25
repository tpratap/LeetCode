class Solution {
public:
     int dp[1001][1001];
    int lcs(string &s, string &r, int n, int m){
        if(m == 0 || n == 0)
            return 0;
        if(dp[n][m] != -1) 
            return dp[n][m];
        return dp[n][m] = (s[n-1] == r[m-1]) ? 1 + lcs(s, r, n-1, m-1) : max(lcs(s, r,n-1,m) , lcs(s , r, n, m-1));
    }
    int longestPalindromeSubseq(string s) {
         int n = s.size();
        string t = s ;
        memset(dp, -1, sizeof(dp));
        reverse(t.begin(), t.end());
        int ans = lcs(s, t, n, t.size());
        return ans;
    }
};