class Solution {
   // int dp[2001][2001];
    // bool isPalindrome(string &s, int i, int j) {
    //     while(i<=j){
    //        if(s[i]==s[j]){
    //            i++;
    //            j--;
    //        }
    //        else{
    //            return false;
    //        }
    //    }
    //    return true;
    // }
//     int palpart(string &str, int i, int j) {
//         if(i >= j)
//             return 0;
        
//          if(dp[i][j] != -1)
//             return dp[i][j];
        
//         if(isPalindrome(str, i, j))
//             return 0;
            
//         int res = INT_MAX;
        
//         for(int k = i; k < j; k++) {
//              if(isPalindrome(str,i,k)) //Optimization
//                  res = min(res, 1 + palpart(str,k+1,j));
//         }
        
//         return dp[i][j] = res;
//     }
public:
    int minCut(string &s) {
        int n = s.length();
        int dp[n];
 /* In the above approach, we can calculate the minimum cut while finding all palindromic substring. If we find all palindromic substring 1st and then we calculate minimum cut, time complexity will reduce to O(n*n).  */
        
        vector<vector<bool>> isPal(n,vector<bool>(n, false));
        
        for(int i = 0; i < n; i++) {
            isPal[i][i] = true;
        }
        

/* L is substring length. Build the solution in bottom up manner by
   considering all substrings of length starting from 2 to n. */
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i < n - L + 1; i++) {
            int j = i + L - 1;
            if (L == 2)
                isPal[i][j] = (s[i] == s[j]);
            else
                isPal[i][j] = (s[i] == s[j]) && isPal[i + 1][j - 1];
        }
    }

    //String starting at j ending at i
    for(int i = 0; i < n; i++) {
        if(isPal[0][i] == true)
                dp[i] = 0;
        else {
            dp[i] = INT_MAX;
            for(int j = 0; j < i; j++) {
                if(isPal[j+1][i])
                    dp[i] = min(dp[i], 1 + dp[j]);

            }
        }
    }
    
// Return the min cut value for complete string. i.e., str[0..n-1]
    return dp[n - 1];
        
        
        // for(int gap = 1; gap < n; gap++) {
        //     for(int i = 0; i+gap < n; i++) {
        //         int j = i + gap;
        //         if((str[i] == str[j]) && (isPal[i+1][j-1] || gap == 1)) {
        //             dp[i][j] = 0;
        //             isPal[i][j] = true;
        //         }
        //         else {
        //             dp[i][j] = INT_MAX;
        //             isPal[i][j] = false;
        //             for(int k = i; k < j; k++) {
        //                 dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + 1);
        //             }
        //         }
        //     }
        // }
        // memset(dp, -1, sizeof(dp));
        // return palpart(str,0,n-1);
       // return dp[0][n-1];
    }
};