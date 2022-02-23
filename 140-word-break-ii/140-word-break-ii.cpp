class Solution {
public:
    unordered_set<string> dict;
    vector<string> ans;
    void helper(string s, string curr) {
        int len = s.size();
        
        if(len == 0) {
            curr.pop_back();
            ans.push_back(curr);
            return;
        }
        
        for(int i = 1; i <= len; i++) {
            if(dict.find(s.substr(0,i)) != dict.end()) {
                helper(s.substr(i,len-i), curr + s.substr(0,i) + " ");
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        for(string str: wordDict) {
            dict.insert(str);    
        }
        
        helper(s, "");
        return ans;
    }
};