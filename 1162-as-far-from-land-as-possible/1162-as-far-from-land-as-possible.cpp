class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int dir[4][2] = {{-1, 0},{0, -1},{0, 1},{1, 0}}; 
        
        int n = grid.size();
        
        vector<vector<int>> dist(n, vector<int>(n , -1));
        
        queue<pair<int,int>> q;
        
        bool zero= true, ones = true;
        
        for(int i=0; i < n; ++i){
            for(int j =0 ; j < n; ++j){
                if(grid[i][j] == 1){
                    dist[i][j] = 0;
                    zero = false; //If all the cells are ones, it will remain true
                    q.push({i, j});  
                } else{
                    ones = false; //If all the cells are ones, it will remain true 
                }
            }
        }
        
        if(zero || ones) // If all cells only contains 0 or 1 then return -1 
            return -1;
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int k =0 ; k < 4; ++k){
                int x = i + dir[k][0];
                int y = j + dir[k][1];
                if(x >= 0 && y >= 0 && x < n && y < n) { //Valid Adjacent
                    if(dist[x][y] == -1) { 
                        if(grid[x][y] == 0) {        //Distance from 1 to 1 is always 0, so upadate 0 to 1 distance only
                            dist[x][y] = 1 + dist[i][j];
                            q.push({x, y});
                        }
                    }
                }
            }
        }
        
        int res = -1;
        for(int i = 0; i <n; ++i){
            for(int j=0; j <n; ++j){
                if(grid[i][j] == 0)
                    res = max(res, dist[i][j]); //Find out the maximum distance
            }
        }
        return res;
    }
};