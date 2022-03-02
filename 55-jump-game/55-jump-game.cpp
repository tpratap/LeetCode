class Solution {
public:
    // int dp[100001];
    // Solution() {
    //     memset(dp, -1, sizeof(dp));
    // }
    
    bool canJump(vector<int>& nums) {
//         if(i == nums.size()-1)
//         return dp[i] = true;
    
//         if(i > nums.size()-1) 
//             return false;

//         if(dp[i]!=-1) 
//             return dp[i];

//         for(int j=1;j<=nums[i];j++) {
//             if(canJump(nums,i+j)) 
//                 return dp[i] = true;
//         }

//         return dp[i] = false;
        //[2 3 1 1 4]  = 4th
        //[3 2 1 0 4] = [3rd]
        //[2,0,6,9,8,4,5,0,8] [8th]
        int n = nums.size();
        int maxJump = 0;
        for(int i = 0; i < n; i++) {
            if(maxJump < i)
                return false;
            maxJump = max(maxJump, i + nums[i]);
        }
        
        return true;
    }
};