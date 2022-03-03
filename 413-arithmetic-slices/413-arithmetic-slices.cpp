class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3)
            return 0;
        
        int cdiff = nums[1] - nums[0];
        int diff = 0;
        int cnt = 0;
        int totalcnt = 0;
        int k = 1;
        
        for(int i = 2; i < nums.size(); ++i) {
            diff = nums[i] - nums[i-1];
            if(diff == cdiff) {
                cnt += k;
                ++k;
            } else {
                totalcnt += cnt;
                cnt = 0;
                cdiff = diff;
                k = 1;
            }
        }
        totalcnt += cnt;
        return totalcnt;
    }
};