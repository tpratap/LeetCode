class Solution {
public:
    /*
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
0 1 1 2 1 2 2 3 1 2 2  3   2  3  3  4  
    */
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0] = 0;
        for(int i = 1; i <= n; ++i) {
            ans[i] = ans[i/2] + i%2;
        }
        return ans;
    }
};