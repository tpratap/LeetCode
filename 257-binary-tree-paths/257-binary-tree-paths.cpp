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
        
        if(root->left == NULL && root->right == NULL) {
            curr.push_back(root->val); 
            ans.push_back(curr);
            return;
        }
        curr.push_back(root->val);
        inorder(root->left,curr);
        //curr.pop_back();
        //curr.push_back(root->val);
        inorder(root->right,curr);
        //curr.pop_back();
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> curr;
        vector<string> res;
        inorder(root, curr);
        for(auto &x: ans) {
            string temp = "";
            for(auto &y: x) {
                temp += to_string(y) + "->";
            }
            temp.pop_back();
            temp.pop_back();
            res.push_back(temp);
        }
        return res;
    }
};