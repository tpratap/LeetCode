class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int dir[4][2] = {{-1, 0},{0, -1},{0, 1},{1, 0}};
        int n = grid.size();
        int res = 0;
        
        vector<vector<int>> dist(n, vector<int>(n , 0));
        
        queue<pair<int,int>> q;
        
        bool zero= true, ones = true;
        
        for(int i=0; i < n; ++i){
            for(int j =0 ; j < n; ++j){
                if(grid[i][j] == 1){
                    zero = false;
                    q.push({i, j});  
                }else{
                    ones = false;
                    dist[i][j] = INT_MAX;
                }
            }
        }
        
        if(zero || ones)
            return -1;
        while(!q.empty()){
            int X = q.front().first;
            int Y = q.front().second;
            q.pop();
            for(int i =0 ; i < 4; ++i){
                int dirX = X + dir[i][0];
                int dirY = Y + dir[i][1];
                if(dirX >= n || dirY >= n || dirY < 0 || dirX < 0)
                    continue;
                if(dist[X][Y] + 1 < dist[dirX][dirY]){
                    if(grid[dirX][dirY] == 0){
                        dist[dirX][dirY] = 1 + dist[X][Y];
                        q.push({dirX, dirY});
                    }
                }
            }
           
        }
        res = -1;
        for(int i = 0; i <n; ++i){
            for(int j=0; j <n; ++j){
                if(grid[i][j] == 0)
                    res = max(res, dist[i][j]);
            }
        }
        return res;
    }
};