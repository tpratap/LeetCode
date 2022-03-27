class Solution {
    int findFirstZero(vector<int>& arr, int n) {
        int low = 0, high = n-1;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[mid] == 0 && (mid == 0 || arr[mid - 1] == 1))
                return mid;
            else if (arr[mid] == 0)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return n;
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>> pq;
        int m = mat.size();
        int n = mat[0].size();
        for(int i = 0; i < m; ++i) {
            int count = findFirstZero(mat[i], n);
            pq.push({count, i});
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};