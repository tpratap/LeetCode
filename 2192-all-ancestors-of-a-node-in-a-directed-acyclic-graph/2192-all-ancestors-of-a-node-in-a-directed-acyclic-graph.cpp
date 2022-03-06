class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        
        vector<int> adj[n];
        
        vector<int> indegree(n, 0);
    
        for(int i=0; i<m; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        
        
        queue<int> q;
        
        for(int i=0; i<n; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        vector<unordered_set<int>> mp(n);
        
        while(!q.empty())
        {
            int  i = q.front();
            q.pop();
            
            for(auto u : adj[i])
            {
                mp[u].insert(i);
                
                for(auto v : mp[i])
                {
                    mp[u].insert(v);
                }
                
                
                
                indegree[u]--;
                
                if(indegree[u] == 0)
                {
                    q.push(u);
                }
            }
            
            
        }
        
        vector<vector<int>> res;
        
        for(int i=0; i<n; i++)
        {
            vector<int> temp;
            
            for(auto v : mp[i])
            {
                temp.push_back(v);
            }
            
            sort(temp.begin(), temp.end());
            
            res.push_back(temp);
        }
        
        
        return res;
    }
};