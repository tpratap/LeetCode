class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i = 0; i < m; ++i) {
            int colxor = 0;
            for(int j = 0; j < n; ++j) {
                int ans = 0;
               //  //cout<<"For Matrix: "<<matrix[i][j]<<"\n";
               //  for(int k = 0; k <= i; ++k) {
               //      for(int l = 0; l <= j; ++l) {
               //          //cout<<matrix[k][l]<<" ";
               //          ans ^= matrix[k][l];
               //      }
               //      //cout<<"\n";
               //  }
               // // cout<<"Ans is: "<<ans<<"\n";
                colxor ^= matrix[i][j];
                if(i > 0)
                    dp[i][j] = colxor ^ dp[i-1][j];
                else
                    dp[i][j] = colxor;
                pq.push(dp[i][j]);
                if(pq.size() > k)
                    pq.pop();
            }
            //cout<<"\n";
        }
        
        return pq.top();
    }
};
// 5 2   5 ^ 2 = 7, 5 ^ 1 = 4, 2 ^ 1 = 3, 1 ^ 6 = 5
// 1 6  m^2n^2 = (mn)^2
// 5 