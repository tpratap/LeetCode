class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int op = 0;
        for(int i = 0; i <  nums.size(); ++i) {
            if(mp[k-nums[i]] > 0) {
                //cout<<(k-nums[i])<<" "<<mp[k-nums[i]]<<"\n";
                mp[k-nums[i]]--;
                
                op++;
            } else {
                //cout<<"Additing"<<nums[i]<<"\n";
                mp[nums[i]]++;
            }
        }
        // for(auto& i: mp)
        //    cout<<i.first<<" "<<i.second<<"\n";
        return op;
    }
};