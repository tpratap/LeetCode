class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> count(k, 0);
        int sum = 0;
        for(int &x : nums) {
            sum += (x%k + k)%k;
            count[sum%k]++;
        }
        
        int result = count[0]; // because for 0 we have n + nC2
        for(int &n: count) {
            result += n*(n-1)/2;
        }
        
        return result;
    }
};