class Solution {
public:
    
    void dfs(string &tiles, unordered_set<string> &s, vector<int> &visited, string curString) {
        if(curString != "") s.insert(curString);
        
        for(int i = 0; i < tiles.size(); i++) {
            if(visited[i]) continue;
            
            visited[i] = 1;
            dfs(tiles, s, visited, curString + tiles[i]);
            visited[i] = 0; // backtrack
        }
    }
    
    int numTilePossibilities(string tiles) {
        unordered_set<string> s;
        vector<int> visited(tiles.size());
        dfs(tiles, s, visited, "");
        return s.size();
    }
};