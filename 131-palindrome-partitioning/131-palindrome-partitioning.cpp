class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string &s, int i, int j) {
        while(i <= j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            }
            else {
                return false;
            }
        }    
        return true;
    }
    
    void palpart(string &s, int i, int j, vector<string> curr) {
        if(i >= j) {
            ans.push_back(curr);
        }
        
        for(int k = i; k < j; k++) {
            if(isPalindrome(s,i,k)) {
                curr.push_back(s.substr(i, k - i + 1));
                palpart(s, k+1, j, curr);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string &s) {
        int n = s.length();
        vector<string> curr;
        palpart(s, 0 , n, curr);
        return ans;
    }
};