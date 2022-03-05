class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        int arr[10001]{};
        int max_val=0;
        for(int i=0;i<n;i++)
        {
            arr[nums[i]]++;
            max_val=max(max_val,nums[i]);
        }
        vector<int>dp(max_val+1,-1);
        dp[0]=0;
        return max_score(arr,max_val,dp);
        
    }
    private:
    int max_score(int*arr,int val,vector<int>&dp)
    {   // if we reach 0, then score is zero.
        if(val<=0)
        return 0;
        //if answer already exists
        if(dp[val]!=-1)
        return dp[val];
        //if delete the element score
        
        int include=val*arr[val]+max_score(arr,val-2,dp);
        //if we do not delete the element
        
        int exclude=max_score(arr,val-1,dp);
        // save the answer in dp array
        dp[val]=max(include, exclude);
        return dp[val];        
    }
};