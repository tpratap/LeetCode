class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxlen = 1, start = 0;
        for(int end = 1; end < nums.size(); ++end) {
            if(nums[end] <= nums[end-1])
                start = end;
            maxlen = max(maxlen, end-start+1);
        }
        return maxlen;
    }
};