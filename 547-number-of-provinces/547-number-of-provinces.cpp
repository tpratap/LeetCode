class Solution {
public:
    void bfs(int src, vector<vector<int>>& isConnected, vector<bool>& visited) {

        queue<int> q;
        q.push(src);
        int V = isConnected.size();
        while(!q.empty()) {    
            src = q.front();
            q.pop();
            for(int j = 0; j < V; j++) { //Neighbours
                if(src != j && isConnected[src][j] == 1)  {
                    if(!visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<bool> visited(V,false);
        int count = 0;
        for(int i = 0; i < V ; i++) {
            if(!visited[i]) {
                visited[i] = true;
                count++;
                bfs(i,isConnected,visited);
            }
        }
        return count;
    }
};