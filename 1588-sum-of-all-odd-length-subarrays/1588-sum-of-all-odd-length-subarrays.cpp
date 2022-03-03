class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        int currsum = 0;
        int n =  arr.size();
        for(int L = 0; L < n; L+=2) {
            for(int i = 0; i+L < n; ++i) {
                int j = i+L;
                currsum = 0;
                for(int k = i; k <= j; ++k) {
                    currsum += arr[k];
                }
                sum += currsum;
            }
        }
        return sum;
    }
};