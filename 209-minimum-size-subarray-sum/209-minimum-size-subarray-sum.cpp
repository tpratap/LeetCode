class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0, left = 0, right = 0, min_len = INT_MAX;
        while(right < n) {
            sum += nums[right];
            if(sum >= target) {
                while(sum >= target) {
                    sum -= nums[left];
                    left++;
                }
                min_len = min(min_len, right-left+2);
            }
            right++;
        }
        return min_len == INT_MAX ? 0: min_len;
    }
};