class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int starti = 0, startj = n-1;
        while(startj >= 0 && starti < m ) {
            if(target == matrix[starti][startj]) {
                return true;
            }
            else if(target < matrix[starti][startj]) {
                startj--;
            }
            else
                starti++;
        }
        return false;
    }
};