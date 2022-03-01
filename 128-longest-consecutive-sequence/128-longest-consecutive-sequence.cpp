class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int &num : nums) {
            s.insert(num);
        }
        
        int maxlen = 0;
        for(auto &num : nums) {
            if(s.find(num-1) == s.end()) {
                int currlen = 1;
                int currnum = num+1;
                while(s.find(currnum) != s.end()) {
                    currnum++;
                    currlen++;
                }
                maxlen = max(currlen, maxlen);
            }
        }
        
        return maxlen;
    }
};