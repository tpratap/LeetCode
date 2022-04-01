class Solution {
    int dp[601][101][101];
    int largestSubset(vector<pair<int, int>> &count, int m, int n, int i) {
        if(i == 0)
            return 0;
        if(m <= 0 && n <= 0)
            return 0;
        if(dp[i][m][n] != -1)
            return dp[i][m][n];
        if(m >= count[i-1].first && n >= count[i-1].second) {
            int include = 1 + largestSubset(count, m - count[i-1].first, n - count[i-1].second, i-1);
            int exclude = largestSubset(count, m, n, i-1);
            dp[i][m][n] = max(include, exclude);
        } else {
            int exclude = largestSubset(count, m, n, i-1);
            dp[i][m][n] = exclude; 
        }
        
        return dp[i][m][n];
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> count(strs.size());
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < strs.size(); ++i) {
            int zeros = 0,ones = 0;
            for(int j = 0; j < strs[i].size(); ++j) {
                if(strs[i][j] == '0')
                    zeros++;
                else
                    ones++;
            }
            count[i] = {zeros, ones};
            //cout<<count[i].first<<" "<<count[i].second<<"\n";
        }
        int ans = largestSubset(count, m, n, strs.size());
        return ans;
    }
};