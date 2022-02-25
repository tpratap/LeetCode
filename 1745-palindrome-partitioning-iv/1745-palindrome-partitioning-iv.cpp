class Solution {
public:

    bool checkPartitioning(string &s) {
        int n = s.size();
        
        int isPal[n][n];
        
        for(int i = 0; i < n; ++i) {
            isPal[i][i] = true;
        }
        
        for (int L = 2; L <= n; ++L) {
            for (int i = 0; i < n - L + 1; ++i) {
                int j = i + L - 1;
                if (L == 2)
                    isPal[i][j] = (s[i] == s[j]);
                else
                    isPal[i][j] = (s[i] == s[j]) && isPal[i + 1][j - 1];
            }
        }

        
        for(int i = 1; i < n-1; ++i) {
            for(int j = i; j < n-1; ++j) {
                if(isPal[0][i-1] && isPal[i][j] && isPal[j+1][n-1]) {
                    return true;
                }
            }
        }
        return false;
    }
};