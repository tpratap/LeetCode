class Solution {
public:
    string longestPalindrome(string &s) {
        int n = s.length();
        
        vector<vector<bool>> isPal(n, vector<bool> (n, false));
        
        for(int i = 0; i < n; i++) 
            isPal[i][i] = true;
        
        for (int L = 2; L <= n; L++) {
            for (int i = 0; i < n - L + 1; i++) {
                int j = i + L - 1;
                if (L == 2)
                    isPal[i][j] = (s[i] == s[j]);
                else
                    isPal[i][j] = (s[i] == s[j]) && isPal[i + 1][j - 1];
            }
        }
        
        int maxlen = 0, l, k;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(isPal[i][j] == true) {
                    int len = j - i + 1;
                    if(len > maxlen) {
                        l = i;
                        k = j;
                        maxlen = len;
                    }
                }
            }
        }
        //cout<<l<<" "<<k<<"\n";
        string ans = s.substr(l, k-l+1);
        return ans;
    }
};