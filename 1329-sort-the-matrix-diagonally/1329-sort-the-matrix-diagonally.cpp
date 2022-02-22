class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<vector<int>> ans;
        int m = mat.size(), n = mat[0].size();
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
        for(int i = 0; i < ans.size(); i++) {
             sort(ans[i].begin(),ans[i].end());
        }
        
//         for(int i = 0; i < ans.size(); i++) {
//             for(int j = 0; j < ans[i].size(); j++)
//                 cout<<ans[i][j]<<" ";
//             cout<<"\n";
//         }
        
//         cout<<"\n\n";
        
        for(int k = 0; k < n; k++)  {
            int j = k,i = 0;
            while(i < m && j < n) {
                mat[i][j] = ans[k][i];
                i++;
                j++;
            }
            
        }
        //0 0 0 1 1 0 2 2 0 0 1 1 1 2 1 2 3 1 0 2 2 1 3 2 0 3 3 
        for(int k = 1, l = n; k < m; k++,l++)  {
            int i = k,j = 0;
            
            while(i < m && j < n) {
                //cout<<i<<" "<<j<<" "<<k<<" ";
                mat[i][j] = ans[l][j];
                i++;
                j++;
            }
        }
        
        // for(int i = 0; i < m; i++) {
        //     for(int j = 0; j < n; j++)
        //         cout<<mat[i][j]<<" ";
        //     cout<<"\n";
        // }
        
        return mat;
    }
};

/*
00 01 02 03
10 11 12 13
20 21 22 23

1 2 3
1 2 3
1 2 
1 
1 2 
1 


03 
*/