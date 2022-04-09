class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        int n = arr.size();
        
        if(n == 0)
            return {};
        
        if(k > n)
            return {};
        
        unordered_map<int,int> mp;
        
        for(int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        
        vector<pair<int,int>> temp;
        
        for(auto x : mp)
        {
            temp.push_back({x.first,x.second});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        for(int i = 0; i < k; i++)
        {
            pq.push({temp[i].second,temp[i].first});
        }
        
        for(int i = k; i < temp.size(); i++)
        {
            if(pq.top().first < temp[i].second)
            {
                pq.pop();
                pq.push({temp[i].second,temp[i].first});
            }
        }
        
        vector<int> res;
        while(pq.empty() == false)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};