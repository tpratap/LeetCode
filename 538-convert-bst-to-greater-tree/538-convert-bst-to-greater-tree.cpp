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
    TreeNode* convertBST(TreeNode* root, int &sum) {
        if(root == NULL)
            return NULL;
        root->right = convertBST(root->right, sum);
        sum += root->val;
        root->val = sum;
        root->left = convertBST(root->left, sum);
        return root;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int sum  = 0;
        return convertBST(root, sum);
    }
};