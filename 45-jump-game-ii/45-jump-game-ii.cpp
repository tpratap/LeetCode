class Solution {
public:
    int minJumps(vector<int>& nums, int idx, vector<int>& dp) {
        if(idx == nums.size()-1)
            return 0;
        
        if(idx > nums.size()-1)
            return INT_MAX;
        
        if(dp[idx] != INT_MAX)
            return dp[idx];
        
        int ans = INT_MAX;
        for(int jump = 1; jump <= nums[idx]; ++jump) {
            int ret = minJumps(nums, idx + jump, dp);
            if(ret != INT_MAX)
            ans = min(ans, 1 + ret);
        }
        return dp[idx] = ans;
    }
    
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size()+1, INT_MAX);
        return minJumps(nums, 0, dp);    
    }
};