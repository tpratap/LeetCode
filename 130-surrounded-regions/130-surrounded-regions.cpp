class Solution {
public:
    int m,n;
    void dfs(vector<vector<char>>& board, int i, int j) {
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O')
            return;
        
        board[i][j] = '1';
        
        dfs(board, i+1, j);
        dfs(board, i, j+1);
        dfs(board, i-1, j);
        dfs(board, i, j-1);
    }
    
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        
        
        for(int j = 0; j < n; j++) {
            //First Row
            if(board[0][j] == 'O')
                dfs(board,0,j);
            
            //Last Row
            if(board[m-1][j] == 'O')
                dfs(board,m-1,j);
        }
        
        
        for(int i = 0; i < m; i++) {
            //First Column
            if(board[i][0] == 'O')
                dfs(board,i,0);
            
            //Last Column
            if(board[i][n-1] == 'O')
                dfs(board,i,n-1);
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '1')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
};