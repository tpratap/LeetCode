class Solution {
public:
    
    /// main logic or trick for this problem : bahar se andar ki taraf jao
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        vector<vector<int>>ans;
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n));
        vector<vector<bool>> atlantic(m, vector<bool>(n));
        
        //kya row k through pani jaa sakta h
        for (int i = 0; i < m; i++) {
            
            dfs(heights, pacific, i, 0);  //pacific ki taraf
            dfs(heights, atlantic, i, n-1); //atlantic ki taraf

        }
        
        //kya column k through pani jaa sakta h
        for (int j = 0; j < n; j++) {
            
            dfs(heights, pacific, 0, j); //pacific ki taraf
            dfs(heights, atlantic, m-1, j); //atlantic ki taraf
        }

        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (pacific[i][j] && atlantic[i][j]) // agar uss particular point se dono oceans mai jaa paa rahe hai
                    ans.push_back({i,j});           // toh answer push kardo
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<int>>& h, vector<vector<bool>>& vis, int i, int j) {
        
        int m = h.size();
        int n = h[0].size();

        vis[i][j] = true;
        //up wala iske through jaa sakta h ya nhi
        if (i-1 >= 0 && vis[i-1][j] != true && h[i-1][j] >= h[i][j])
            dfs(h, vis, i-1, j);
        //down wala iske through jaa sakta h ya nhi
        if (i+1 < m && vis[i+1][j] != true && h[i+1][j] >= h[i][j])
            dfs(h, vis, i+1, j);
        //left wala iske through jaa sakta h ya nhi
        if (j-1 >= 0 && vis[i][j-1] != true && h[i][j-1] >= h[i][j])
            dfs(h, vis, i, j-1);
        //right wala iske through jaa sakta h ya nhi
        if (j+1 < n && vis[i][j+1] != true && h[i][j+1] >= h[i][j])
            dfs(h, vis, i, j+1);

    }
};