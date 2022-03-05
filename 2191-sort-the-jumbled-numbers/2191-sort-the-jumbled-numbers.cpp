class Solution {
    long long Map(int &num, vector<int>& mapping) {
        string s = to_string(num);
        for(int i = 0; i < s.length(); ++i) {
            s[i] = mapping[s[i]-'0'] + '0';
        }
        return stoll(s);
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<long long, int>> ans;
        for(int i = 0; i < nums.size(); ++i) {
            long long mapped = Map(nums[i], mapping);
            ans.push_back({mapped, nums[i]});
        }
        
        sort(ans.begin(), ans.end(), [&] (const pair<long long, int> &p1, const pair<long long, int> &p2) {
            return p1.first < p2.first;
        });
        
        for(int i = 0; i < nums.size(); ++i)
            nums[i] = ans[i].second;
        return nums;
    }
};