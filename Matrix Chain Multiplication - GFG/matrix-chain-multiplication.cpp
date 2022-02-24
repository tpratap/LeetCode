// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // int dp[101][101];
    // int MCM(int arr[], int i, int j) {
    //     if(i+1 == j)
    //         return dp[i][j] = 0;
        
            
    //     int res = INT_MAX;
    
    //     if(dp[i][j] != -1)
    //         return dp[i][j];
            
    //     for(int k = i+1; k < j; k++) {
    //         res = min(res, MCM(arr,i,k) + MCM(arr, k, j) + arr[i]*arr[k]*arr[j]);
    //     }
        
    //     return dp[i][j] = res;
    // }
    int matrixMultiplication(int N, int arr[])
    {
        //memset(dp,-1,sizeof(dp));
        //return MCM(arr, 0, N-1);
        int dp[N][N];
        
        for(int i = 0; i < N-1; i++) {
            dp[i][i+1] = 0;
        }
        
        for(int gap = 2; gap < N; gap++) {
            for(int i = 0; i + gap < N; i++) {
                int j = i + gap;
                dp[i][j] = INT_MAX;
                
                for(int k = i+1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j]);
                }
            } 
        }
        return dp[0][N-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends