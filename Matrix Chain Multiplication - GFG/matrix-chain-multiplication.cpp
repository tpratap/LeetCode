// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[501][501];
    int MCM(int arr[], int i, int j) {
        if(i+1 == j)
            return dp[i][j] = 0;
        
            
        int res = INT_MAX;
    
        if(dp[i][j] != -1)
            return dp[i][j];
            
        for(int k = i+1; k < j; k++) {
            res = min(res, MCM(arr,i,k) + MCM(arr, k, j) + arr[i]*arr[k]*arr[j]);
        }
        
        return dp[i][j] = res;
    }
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        return MCM(arr, 0, N-1);
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