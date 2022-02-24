// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[501][501];
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
        if(isPalindrome(str, i, j))
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
            
        int res = INT_MAX;
        
        for(int k = i; k < j; k++) {
            res = min(res, palpart(str,i,k) + palpart(str, k+1, j) + 1);
        }
        
        return dp[i][j] = res;
    }
    int palindromicPartition(string &str)
    {
        int n = str.length();
        memset(dp, -1, sizeof(dp));
        palpart(str,0,n-1);
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