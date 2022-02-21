class Solution {
public:
    unordered_map<string,bool>dp;
    bool recur(string s1,string s2,string &s3, int idx1, int idx2,int idx3){
        if(idx3 == s3.size()){
            return true;
        }
        string key = to_string(idx1)+""+to_string(idx2)+""+to_string(idx3);
        if(dp.count(key)!=0)
            return dp[key];
        
        bool ans = false;
        
        if(s3[idx3] == s1[idx1] && s3[idx3] == s2[idx2]){
            ans = recur(s1,s2,s3,idx1,idx2+1,idx3+1) || recur(s1,s2,s3,idx1+1,idx2,idx3+1);
        }
        else if(s3[idx3] == s1[idx1]){
            ans = recur(s1,s2,s3,idx1+1,idx2,idx3+1);
        }else if(s3[idx3] == s2[idx2]){
            ans = recur(s1,s2,s3,idx1,idx2+1,idx3+1);
        }else{
            ans = false;
        }
        
        return dp[key] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        string temp = (s1+s2);
        int freq[26] = {};
        for(auto ch:temp){
            freq[ch-'a']++;
        }
        for(auto ch:s3){
            freq[ch-'a']--;
        }
        for(auto val:freq){
            if(val<0 || val>0)
                return false;
        }
        
        return recur(s1,s2,s3,0,0,0);
    }
};