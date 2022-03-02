class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int row = 0;
        int low = 0, high = m-1;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(matrix[mid][0] == target || matrix[mid][n-1] == target)
                return true;
            else if(matrix[mid][0] < target && matrix[mid][n-1] > target) {
                row = mid;
                break;
            }
            else if(matrix[mid][0] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        
        //cout<<row<<" ";
        
        low = 0, high = n-1;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(matrix[row][mid] == target)
                return true;
            else if(matrix[row][mid] > target) 
                high = mid - 1;
            else 
                low = mid + 1;
        }
        
        return false;
    }
};








