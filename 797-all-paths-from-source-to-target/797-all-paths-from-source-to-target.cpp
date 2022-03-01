class Solution {
    vector<vector<int>> ans;
public:
    void dfs(vector<vector<int>>& graph, int& target, int src, vector<int> curr) {
        curr.push_back(src);
        
        if(src == target) {
            ans.push_back(curr);
            return;
        }
        
        for(auto &neigh : graph[src]) {
            dfs(graph,target, neigh, curr);
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target = graph.size()-1;
        dfs(graph, target, 0, {});
        return ans;
    }
};