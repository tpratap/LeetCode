class Solution {
    void mark_current_island(vector<vector<char>> &grid,int i,int j,int row,int cols)
    {
        if(i < 0 || i >= row || j < 0 || j >= cols || grid[i][j] != '1')  
            return;
        
        grid[i][j] = '2';
        
        mark_current_island(grid,i+1,j,row,cols);  
        mark_current_island(grid,i,j+1,row,cols);  
        mark_current_island(grid,i-1,j,row,cols);  
        mark_current_island(grid,i,j-1,row,cols); 
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int rows = grid.size();
        if(rows==0)    
            return 0;
        int cols = grid[0].size();
        
        int islands = 0;
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(grid[i][j]=='1')
                {
                    mark_current_island(grid,i,j,rows,cols);
                    islands += 1;
                }
            }
        }
        return islands;
    }
};