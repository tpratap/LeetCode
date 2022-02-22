/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;
    void inorder(TreeNode* root, vector<int> curr) {
        if(root == NULL) {
            return;
        }
        
        curr.push_back(root->val);
        
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(curr);
            return;
        }
        
        inorder(root->left,curr);
        inorder(root->right,curr);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> curr;
        vector<string> res;
        inorder(root, curr);
        for(int i = 0; i < ans.size(); i++) {
            int j;
            string temp = "";
            for(j = 0; j < ans[i].size()-1; j++) {
                temp += to_string(ans[i][j]) + "->";
            }
            temp += to_string(ans[i][j]);
            res.push_back(temp);
        }
        return res;
    }
};