typedef long long LL;
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        LL sum = (1LL + k) * k / 2;
        LL cnt = 0;
        unordered_set<LL> Set(nums.begin(), nums.end());
        for (auto i : Set) {
            if (i >= 1 && i <= (1 + k - 1)) {
                sum -= i;
                cnt++;
            }
        }
        
        LL target = k + 1LL;
        while (cnt--) {
            while (Set.find(target) != Set.end()) {
                target++;
            }
            sum += target;
            target++;
        }
        return sum;
    }
};