class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res = 0;
        int n = arr.size();
        for(int i = 0; i < n; ++i) {
            int start = n - i; //subarrays starting at index i
            int end = i + 1;   // subarrays ending at index i
            int total = start*end; //Total subarrays that contains i
            int odd = total/2; // odd length subarrays that contains i
            if(total%2 == 1) {
                odd++; // Odd = even or odd = even + 1
            }
            res += odd*arr[i]; // Sum contributed by arr[i] is product of its occurance and its value 
        }
        return res;
    }
};