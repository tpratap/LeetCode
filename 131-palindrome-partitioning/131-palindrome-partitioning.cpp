class Solution {
public:
    vector<vector<string>> ans;
    
    void palpart(string &s, int i, int j, vector<string> curr, vector<vector<bool>> &isPal) {
        if(i >= j) {
            ans.push_back(curr);
        }
        
        for(int k = i; k < j; k++) {
            if(s[i] == s[k] && ( k - i <= 2 || isPal[i+1][k-1])) {
                isPal[i][k] = true;
                curr.push_back(s.substr(i, k - i + 1));
                palpart(s, k+1, j, curr, isPal);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string &s) {
        int n = s.length();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        vector<string> curr;
        palpart(s, 0 , n, curr, isPal);
        return ans;
    }
};