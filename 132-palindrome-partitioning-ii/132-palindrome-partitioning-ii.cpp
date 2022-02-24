class Solution {
    int dp[2001][2001];
    bool isPalindrome(string &s, int i, int j) {
        while(i<=j){
           if(s[i]==s[j]){
               i++;
               j--;
           }
           else{
               return false;
           }
       }
       return true;
    }
    int palpart(string &str, int i, int j) {
        if(i >= j)
            return 0;
        
         if(dp[i][j] != -1)
            return dp[i][j];
        
        if(isPalindrome(str, i, j))
            return 0;
            
        int res = INT_MAX;
        
        for(int k = i; k < j; k++) {
             if(isPalindrome(str,i,k)) //Optimization
                 res = min(res, 1 + palpart(str,k+1,j));
        }
        
        return dp[i][j] = res;
    }
public:
    int minCut(string &str) {
        int n = str.length();
        memset(dp, -1, sizeof(dp));
        return palpart(str,0,n-1);
    }
};