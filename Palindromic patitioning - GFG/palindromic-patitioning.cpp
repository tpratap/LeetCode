// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
// int dp[501][501];
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
//     int palpart(string &str, int i, int j) {
//         if(isPalindrome(str, i, j))
//             return 0;
        //   if(i >= j)
        //     return 0;
//         if(dp[i][j] != -1)
//             return dp[i][j];
            
//         int res = INT_MAX;
        
//         for(int k = i; k < j; k++) {
//             res = min(res, palpart(str,i,k) + palpart(str, k+1, j) + 1);
//         }
        
//         return dp[i][j] = res;
//     }
    int palindromicPartition(string &str)
    {
        int n = str.length();
        int dp[n][n];
        
        for(int i = 0; i < n; i++) {
            dp[i][i] = 0;
        }
        
        for(int gap = 1; gap < n; gap++) {
            for(int i = 0; i+gap < n; i++) {
                int j = i + gap;
                if(isPalindrome(str, i, j))
                    dp[i][j] = 0;
                else {
                    dp[i][j] = INT_MAX;
                    for(int k = i; k < j; k++) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + 1);
                    }
                }
            }
        }
        // memset(dp, -1, sizeof(dp));
        // return palpart(str,0,n-1);
        return dp[0][n-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends