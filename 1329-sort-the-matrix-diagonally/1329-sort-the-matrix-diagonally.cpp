class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<vector<int>> ans;
        int m = mat.size(), n = mat[0].size();
        
        //upper triangular matrix
        for(int k = 0; k < n; k++)  {
            int j = k,i = 0;
            vector<int> temp;
            while(i < m && j < n) {
                temp.push_back(mat[i][j]);
                i++;
                j++;
            }
            ans.push_back(temp);
        }
        
        //lower triangular matrix
        for(int k = 1; k < m; k++)  {
            int i = k,j = 0;
            vector<int> temp;
            while(i < m && j < n) {
                temp.push_back(mat[i][j]);
                i++;
                j++;
            }
            ans.push_back(temp);
        }
        
        //Sort Matrix Diagonally
        for(int i = 0; i < ans.size(); i++) {
             sort(ans[i].begin(),ans[i].end());
        }
        
        //upper triangular matrix
        for(int k = 0; k < n; k++)  {
            int j = k,i = 0;
            while(i < m && j < n) {
                mat[i][j] = ans[k][i];
                i++;
                j++;
            }
            
        }
        
        //lower triangular matrix
        for(int k = 1, l = n; k < m; k++,l++)  {
            int i = k,j = 0;
            while(i < m && j < n) {
                mat[i][j] = ans[l][j];
                i++;
                j++;
            }
        }
        
        
        return mat;
    }
};
