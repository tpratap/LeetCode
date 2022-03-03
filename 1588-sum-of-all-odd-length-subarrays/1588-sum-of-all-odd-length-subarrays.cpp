class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        int currsum = 0;
        int n =  arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int L = 0; L < n; L+=2) {
            for(int i = 0; i+L < n; ++i) {
                int j = i+L;
                if(i == j)
                    dp[i][j] = arr[i];
                else
                    dp[i][j] = dp[i+1][j-1] + arr[i] + arr[j];
                // currsum = 0;
                // for(int k = i; k <= j; ++k) {
                //     currsum += arr[k];
                // }
                sum += dp[i][j];
            }
        }
        return sum;
    }
};

/*
1               1
4               4
2               2
5               5
3               3
1 4 2          
4 2 5
2 5 3
1 4 2 5 3

*/