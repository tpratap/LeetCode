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
    vector<int> temp ;
    void inorder(TreeNode *root){
        if(root == NULL) return ;
        inorder(root->left);
        temp.push_back(root->val);
        inorder(root->right);
        return;
    }
    TreeNode *constructBST(int start, int end){
        if(start > end) return NULL;
        int mid = ( start + end )/2 ;
        TreeNode *t = new TreeNode(temp[mid]);
        t->left = constructBST(start, mid - 1);
        t->right = constructBST(mid+1, end);
        return t;
    }
    TreeNode* balanceBST(TreeNode* root) {
            inorder(root);
            int start = 0 ;
            int end = temp.size() - 1;
            TreeNode *newRoot = constructBST(start, end);
            return newRoot;
        }
};