class Solution {
public:
    int dp[100001];
    Solution() {
        memset(dp, -1, sizeof(dp));
    }
    
    bool canJump(vector<int>& nums, int i = 0) {
        if(i == nums.size()-1)
        return dp[i] = true;
    
        if(i > nums.size()-1) 
            return false;

        if(dp[i]!=-1) 
            return dp[i];

        for(int j=1;j<=nums[i];j++) {
            if(canJump(nums,i+j)) 
                return dp[i] = true;
        }

        return dp[i] = false;
    }
};