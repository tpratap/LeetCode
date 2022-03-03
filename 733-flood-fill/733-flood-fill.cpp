class Solution {
public:
    int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    void dfs(vector<vector<int>>& image, int sr, int sc, int &newColor, int prevColor, vector<vector<bool>>& visited) {
        if(sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] != prevColor)
            return;
        
        if(visited[sr][sc])
            return;
        
        image[sr][sc] = newColor;
        visited[sr][sc] = true;
        
        for(int k = 0; k < 4; ++k) {
            int x = sr + dir[k][0];
            int y = sc + dir[k][1];
            dfs(image, x, y, newColor, prevColor, visited);
        }
    }
    /*
        0 0 0
        0 1 1
    */
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int prevColor = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        dfs(image,sr,sc,newColor, prevColor, visited);
        return image;
    }
};