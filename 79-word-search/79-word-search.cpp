class Solution {
public:
    string ans;
    int dir[4][2] = {{-1,0},{0,1}, {1,0},{0,-1}};
    void dfs(vector<vector<char>>& board, string word,int idx, string curr, int i, int j, vector<vector<bool>>& visited)     {
        if(idx == word.length()) {
            ans = curr;
            return;
        }
        
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j])
            return;
        
        if(word[idx] != board[i][j])
            return;
        
        visited[i][j] = true;
        curr.push_back(board[i][j]);
        
        for(int k = 0; k < 4; k++) {
            int x = i + dir[k][0];
            int y = j + dir[k][1];
            dfs(board, word, idx+1, curr, x, y, visited);
        }
        
        //backtrack
        curr.pop_back();
        visited[i][j] = false;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
       
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                    dfs(board,word,0,"",i,j, visited);
                    if(ans == word)
                        return true;
                }
            }
        }
        return false;
    }
};