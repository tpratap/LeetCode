template<typename T>
class myCompare
{
public:
    int operator() (const pair<T,int> &p1, const pair<T, int> &p2)
    {
        return p1.second < p2.second;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //u, v, w
        unordered_map<int, vector<pair<int, int>>> graph;
        for(int i = 0; i < times.size(); ++i) {
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        
        vector<int> dist(n+1, INT_MAX);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,myCompare<int>> pq;
		dist[k] = 0;
		pq.push({k,0});
		while(!pq.empty()) {
			int u = pq.top().first;
			pq.pop();
			for(auto neighbour: graph[u]) {
				int v = neighbour.first;
				int weight = neighbour.second;
				if(dist[v] > dist[u] + weight) {
					dist[v] = dist[u] + weight;
						pq.push({v,dist[v]});
				}
			}
		}
        
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            if(dist[i] == INT_MAX)
                return -1;
            else
                ans = max(ans, dist[i]);
        }
        
        return ans;
    }
};