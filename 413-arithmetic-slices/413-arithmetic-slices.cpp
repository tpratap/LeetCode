class Solution {
public:
    /*
    By Observartion,
    AP Length     | No. of Combinations
    3 [1,2,3]     | 1 (0+1) prev+1
    4 [1,2,3,4]   | 3 (1+2) prev+2
    5 [1,2,3,4,5] | 6 (3+3) prev+3
    To the previoius value we are adding 1,then 2,then 3 as length of AP is increasing.
    In the code k represents the value to be added.
    */
    int numberOfArithmeticSlices(vector<int>& A) {
        int n=A.size();
        if(n<3) return 0;
        
        int dif=A[1]-A[0],k=1;  // k : value to be added as length of AP is increasing
        int cnt=0,tcnt=0; // cnt : count of single AP combinations
        for(int i=2;i<n;++i){
            
            int d =A[i]-A[i-1];
            
            if(d==dif){
                cnt+=k;
                ++k;
            }else{
                dif=d;
                tcnt+=cnt;
                k=1; cnt=0;
            }
            
        }
        tcnt+=cnt;
        return tcnt;
    }
};