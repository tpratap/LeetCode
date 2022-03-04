class Solution {
public:
    
    int x[4] = {1,0,-1,0};
    int y[4] = {0,-1,0,1};
    
    void dfs(vector<vector<int>>&grid,int i ,int j, int n, int m){
        
        if(i< 0 || j< 0 || i>=n || j>=m || grid[i][j] == 0)
            return;
        
        grid[i][j] = 0;
        
        for(int k = 0;k<4;k++){
            int nx = i+x[k];
            int ny = j + y[k];
            dfs(grid,nx,ny,n,m);
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int j = 0;j<m;j++){
            if(grid[0][j])
            dfs(grid,0,j,n,m);
             if(grid[n-1][j])
            dfs(grid,n-1,j,n,m);
        }
         for(int i = 0;i<n;i++){
            if(grid[i][0])
            dfs(grid,i,0,n,m);
            if(grid[i][m-1])
            dfs(grid,i,m-1,n,m);
        }
        int count = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j])
                   count++;
            }
        }
        
        return count;
    }
};