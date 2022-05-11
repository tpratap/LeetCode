class Solution {
public:
    // a e i o u
    // a+5, e + 4, i + 3, o+2, u+1
   /*
        5
 a  [aa,ae,ai,ao,au] -> [5,4,3,2,1]->[25,16,9,4,1]
 e   [ee,ei,eo,eu]   -> [4,3,2,1]
 i   [ii,io,iu]  ->[3,2,1]
 o  [oo,ou] -> [2,1]
 u  [uu]    ->[1]
 
 [1,1,1,1,1] i-1, j
 [5,  4,3,2,1]i,j+1
 [15,10,6,3,1]
   
   
   */
    
    
    
    int countVowelStrings(int n) {
        int dp[n][5];
        int ans = 0;
        for(int i = 0; i < 5; i++)
            dp[0][i] = 1;
        for(int i = 0; i < n; i++)
            dp[i][4] = 1;
        for(int i = 1; i < n; i++) {
            for(int j = 3; j >= 0; j--) {
                dp[i][j] = (dp[i-1][j]+dp[i][j+1]);
            }
        }
        for(int i = 0; i < 5; i++)
            ans = ans + dp[n-1][i];

         return ans;
    }
};