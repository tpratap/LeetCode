class Solution {
public:
    int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
    bool dfs(vector<vector<int>> &grid,vector<vector<bool>> &visited,int m, int n,int i,int j)
    {
        visited[i][j]=1;
        if(i == 0|| i == m-1 || j==0 || j == n-1)
            return false;
        
        bool ans = true;
        
        for(int k=0;k<4;k++)
        {
            int x = i + dir[k][0];
            int y = j + dir[k][1];
            
            if(x >= 0 && y >= 0 && x < m && y < n && !visited[x][y] && grid[x][y] == 0)
            {
                if(!dfs(grid,visited, m, n, x, y))
                    ans=false;
            }
        }
        return ans;
    }
    
    
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int closedIslands=0;
        for(int i = 1;i < m-1 ; i++)
        {
            for(int j = 1;j < n-1; j++)
            {
                if(!visited[i][j] && grid[i][j]==0)
                {
                    if(dfs(grid,visited,m,n,i,j))
                    {
                        closedIslands++;
                    }
                }
            }
        }
        return closedIslands;
        
    }
};