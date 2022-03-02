class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxJump = 0;
        int jumps = 0;
        int prevmaxJump = 0;
        for(int i = 0; i < n; ++i) {
            if(prevmaxJump < i) {
                jumps++;
                prevmaxJump = maxJump;
            }
            //cout<<i<<" "<<jumps<<"\n";
            maxJump = max(maxJump, i+nums[i]);
        }
        return jumps;
    }
};