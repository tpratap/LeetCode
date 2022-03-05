class Solution {
    int m,n;
    int dir[4][2] = {{-1,0},{0,-1}, {0,1},{1,0}};;
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, bool &flag) {
        if(i < 0 || j < 0 || i >= m || j >= n || grid2[i][j] == 0)
            return;
        
        grid2[i][j] = 0;
       
        
        if(grid1[i][j] != 1)
            flag = false;
        
        
        for(int k = 0; k < 4; ++k) {
            int x = i + dir[k][0];
            int y = j + dir[k][1];
            dfs(grid1, grid2, x, y, flag);
        }
        
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();
        int countSubIsland = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid2[i][j] == 1 && grid1[i][j] == 1) {
                    bool flag = true;
                    dfs(grid1, grid2, i, j, flag);
                    if(flag) {
                        // cout<<i<<" "<<j<<"\n";
                        countSubIsland++;
                    }
                }
            }
        }
        
        return countSubIsland;
    }
};