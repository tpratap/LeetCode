class Solution {
public:
    vector<int> partitionLabels(string s) {
        int lastpos[26] = {0};
        for(int i = 0; i < s.length(); i++) {
            lastpos[s[i]-'a'] = i;
        }
        
        vector<int> ans;
        int lastposofgroup = 0, startposofgroup = 0;
        for(int i = 0; i < s.length(); i++) {
            lastposofgroup = max( lastposofgroup, lastpos[s[i]-'a']);
            
            if(i == lastposofgroup) {
                int currentgrouplength = lastposofgroup-startposofgroup+1;
                ans.push_back(currentgrouplength);
                startposofgroup = i+1;
            }
        }
        
        return ans;
    }
};