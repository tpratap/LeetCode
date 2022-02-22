class Solution {
public:
    vector<vector<int>> dp;
    bool match(string &s, string &p, int i, int j) {
        
        //If pattern is empty, and string is also empty then return true, else return false
        if(j == p.length())  
            return i == s.length();
        
        //If s becomes empty but pattern is not completed
        if(i > s.length())
            return false;
        
        bool ans;
        
        //Memoization step
        if(dp[i][j] != -1)
           return dp[i][j];
        
        //If pattern[j] is '*', then it can match to empty string as well as length of anystring
        if(p[j] == '*')
            ans = match(s, p , i , j+1) || match(s, p , i+1, j);
        //If pattern[j] is '?' then it must match from next character as well as if pattern[j] is matching with string[i] then we should check for rest of string
        else
            ans = (p[j] == '?' || p[j] == s[i]) && match(s, p, i+1, j+1);
        
        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        dp.assign(n+1, vector<int>(m+1, -1));
        return match(s,p,0,0);
    }
};