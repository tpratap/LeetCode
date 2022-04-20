class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();
        vector<int> ans(m*n);
        int i, k = 0, l = 0, idx = 0;
        while (k < m && l < n) {
            for (i = l; i < n; ++i) {
                ans[idx] = a[k][i];
                ++idx;
            }
            k++;
            for (i = k; i < m; ++i) {
                ans[idx] = a[i][n - 1];
                ++idx;
            }
            n--;
            if (k < m) {
                for (i = n - 1; i >= l; --i) {
                    ans[idx] = a[m - 1][i];
                    ++idx;
                }
                m--;
            }
            if (l < n) {
                for (i = m - 1; i >= k; --i) {
                    ans[idx] = a[i][l];
                    ++idx;
                }
                l++;
            }
        }
        return ans;
    }
};