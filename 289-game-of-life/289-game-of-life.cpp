class Solution {
public:
    /*
    State 0: Dead cell stays dead
    State 1: Live cell starys live
    State 2: Live cell turns into dead
    State 3: Dead cell turns into live
    */
    void gameOfLife(vector<vector<int>>& board) {
        
        int dir[8][2] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int count = 0;
                for(int k = 0; k < 8; k++) {
                    int x = dir[k][0]+i;
                    int y = dir[k][1]+j;
                    if(x < 0 || y < 0 || x >= m || y >= n)
                        continue;
                    if(board[x][y] == 1 || board[x][y] == 2)
                        count++;
                }
                if(board[i][j] == 1 && (count > 3 || count < 2))
                        board[i][j] = 2;
                else if(board[i][j] == 0 && count == 3)
                    board[i][j] = 3;
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                board[i][j] %= 2;
            }
        }
    }
};

