class Solution {
public:
//     int solve(vector<vector<int>>& triangle, int i, int j) {
            
//     }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j <= i; ++j) {
                if(j == 0)
                    triangle[i][j] += triangle[i-1][j];
                else if(j == i)
                    triangle[i][j] += triangle[i-1][j-1];
                else
                    triangle[i][j] += min(triangle[i-1][j] ,triangle[i-1][j-1]);
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; ++i)
            ans = min(ans, triangle[n-1][i]);
        
        return ans;
    }
};