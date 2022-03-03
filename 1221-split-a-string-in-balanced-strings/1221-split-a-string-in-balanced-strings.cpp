class Solution {
public:
    int balancedStringSplit(string &s) {
        int i = 0, res = 0, count = 0;
        while(i < s.length()) {
            if(s[i] == 'L')
                ++count;
            else
                --count;
            if(count == 0)
                ++res;
            ++i;
        }
        return res;
    }
};