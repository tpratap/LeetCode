class Solution {
unordered_set<string> s;
public:
    void dfs(string &tiles, string curr, vector<int> visited) {
        if(curr != "") s.insert(curr);
        for(int j = 0; j < tiles.size(); ++j) {
            if(visited[j])
                continue;
            visited[j] = 1;
            curr.push_back(tiles[j]);
            dfs(tiles, curr, visited);
            visited[j] = 0;
            curr.pop_back();
        } 
    }
    int numTilePossibilities(string &tiles) {
        vector<int> visited(tiles.size());
        dfs(tiles, "", visited);
        return s.size();
    }
};