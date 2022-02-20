class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,false);
        visited[0] = true;
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int vertex = q.front();
            q.pop();
            for(auto v: rooms[vertex]) {
                if(!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(!visited[i])
                return false;
        }
        
        return true;
    }
};
