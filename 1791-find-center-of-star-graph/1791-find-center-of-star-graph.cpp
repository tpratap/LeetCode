class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> outdegree;
        for(int i = 0; i < edges.size(); i++) {
            outdegree[edges[i][0]]++;
            outdegree[edges[i][1]]++;
        }
        int n = outdegree.size();
        for(auto &it: outdegree) {
            if(it.second == n-1)
                return it.first;
        }
        return -1;
    }
};