class Solution {
public:
    unordered_set < string > hashMap;
    unordered_map<string, int> dp;
    bool wordBreakHelper(string s) {

        // Len denotes size of current string.
        int len = s.size();

        // Base case.
        if (len == 0) {
            return true;
        }

        if(dp.count(s) > 0)
            return dp[s];
        
        // Run a loop from 1 to length of target string.
        for (int i = 1; i <= len; i++) {
            /*
                If substring from 0 to i exist in hash map
                and remaining string recurs true then return true.
            */
            if (hashMap.find(s.substr(0, i)) != hashMap.end() and wordBreakHelper(s.substr(i, len - i))) {
                return dp[s] = true;
            }
        }

        // If no solution exist then return false.
        return dp[s] = false;
    }

    bool wordBreak(string &s, vector<string>& wordDict) {
      

        // Insert all strings of a into hashmap.
        for (string str: wordDict) {
            hashMap.insert(str);
        }

        // Call wordBreakHelper to return answer.
        return wordBreakHelper(s);
    }
};