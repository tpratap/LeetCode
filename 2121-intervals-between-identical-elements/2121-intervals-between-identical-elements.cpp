class Solution {
public:
    vector<long long> getDistances(vector<int>& a) {
        long long n = a.size();
        vector<long long> ans(n,0);
        unordered_map<long long,pair<long long,long long>> left; 
        for(int i = 0;i < n; ++i) {
            long long leftCount = left[a[i]].first; 
            long long leftSum = left[a[i]].second;  
            ans[i] = leftCount*i - leftSum;
            left[a[i]].first += 1; 
            left[a[i]].second += i; 
        }

        unordered_map<long long,pair<long long,long long>> right;
        for(int i=n-1;i>=0;--i) {
            long long rightCount = right[a[i]].first; 
            long long rightSum = right[a[i]].second; 
            ans[i] += rightSum - rightCount*i;
            right[a[i]].first += 1;  
            right[a[i]].second += i;  
        }
        return ans;
    }
};