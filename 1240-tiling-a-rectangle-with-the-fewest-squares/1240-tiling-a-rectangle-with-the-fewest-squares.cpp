class Solution {
public:
    int DP[15][15];
        
    int solve(int n, int m) {
        if (m < n)
            swap(m, n);
        if (n == 0 || m == 0)
            return 0;
        if (n == m)
            return 1;        
        if (n == 1)
            return m;
        if (m == 1)
            return n;
        if (DP[n][m] != -1)
            return DP[n][m];
        
        DP[n][m] = 1 + solve(n, m - n);        
        for (int s = n - 1; s >= 1; s--) {            
            for (int k = 1; k < n; k++) {
                if (s + k < n) //rect1 and rect3 intersect: invalid.
                    continue;
                if (s + k > m) //cannot span more than m: invalid.
                    break;
                int rect1 = solve(n - s, m - k);
                int rect2 = solve(s + k - n, m - s - k);
                int rect3 = solve(n - k, m - s);
                DP[n][m] = min(DP[n][m], 2 + rect1 + rect2 + rect3);
            }
        }
        return DP[n][m];
    }
    
    
    int tilingRectangle(int n, int m) {
        memset(DP, -1, sizeof(DP));        
        return solve(n, m);
    }
};