class Solution {
public:
    unordered_map<int, vector<int>> graph;
    
    bool insideCircle(int x1, int y1, int r1, int x2, int y2) {
        int dist = ceil(sqrt( pow(abs(x2-x1),2) + pow(abs(y2-y1),2) ));
        return (dist <= r1);
    }
    
    int bfs(int src, vector<bool>& visited) {
        queue<int> q;
        q.push(src);
        visited[src] = true;
        int count = 0;
        while(!q.empty()) {
            src = q.front();
            q.pop();
            count++;
            for(auto neigh: graph[src]) {
                if(!visited[neigh]) {
                    visited[neigh] = true;
                    q.push(neigh);
                }
            }
        }
        return count;
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        //Generate Graph for which we can detonate bombs
        int n = bombs.size();
        for(int i = 0; i < n; i++) {
            int x1 = bombs[i][0];
            int y1 = bombs[i][1];
            int r1 = bombs[i][2];
            for(int j = 0; j < n; j++) {
                int x2 = bombs[j][0];
                int y2 = bombs[j][1];
                if(i != j && insideCircle(x1,y1,r1,x2,y2)) {
                    graph[i].push_back(j);
                }
            }
        }
        
        //Check for number of connected components and count for detonated bombs
        // by taking different source and find the maximum
        int maxBombs = 0;
        for(int i = 0; i < n; i++) {
            vector<bool> visited(n,false);
            int count = bfs(i,visited);
            maxBombs = max(count, maxBombs);
        }
        
        return maxBombs;
    }
};