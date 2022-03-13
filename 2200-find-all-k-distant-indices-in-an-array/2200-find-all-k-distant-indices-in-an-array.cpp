class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int N = nums.size(), j = 0;
        vector<int> ans;
        for (int i = 0, j = 0; i < N; ++i) {
            while (j < N && (nums[j] != key || j < i - k)) 
                ++j; 
            if (j == N) 
                break;
            if (i <= j + k && i >= j - k) 
                ans.push_back(i); 
        }
        return ans;
    }
};