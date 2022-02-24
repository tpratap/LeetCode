class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        //to check local inversions we just need to verify if in the given array element is shifted at most 1 position from its correct position in the sorted array.
        //If it is shifted more than one posdition, then extra global inversion occurs
        for(int i = 0 ; i < A.size() ; i++){
            if(abs(A[i] - i) > 1)
                return false;
        }
        return true;
    }
};