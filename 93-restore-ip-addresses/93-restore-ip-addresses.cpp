class Solution {
public:
    
    vector<string>ans;
    
    bool check(string s){
        if(s[0] == '0')
            return false;
        int digit = stoi(s);
        if(digit<=255)
            return true;
        return false;
    }
    void helper(string &s,string curr,int i,int par){
        if(i == s.size() || par == 4){
           
            if(i==s.size() && par == 4){
                curr.pop_back();
                ans.push_back(curr);
            }
           
            return;
        }
        
        
        helper(s,curr+s.substr(i,1)+'.',i+1,par+1);
    
        if(i+2<=s.size() && check(s.substr(i,2))){
         helper(s,curr+s.substr(i,2)+'.',i+2,par+1);
       }
        if(i+3<=s.size() && check(s.substr(i,3))){
          helper(s,curr+s.substr(i,3)+'.',i+3,par+1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        
        helper(s,"",0,0);
        return ans;
    }
};