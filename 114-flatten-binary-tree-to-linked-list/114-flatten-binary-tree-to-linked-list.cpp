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

/*              1(1, NULL)
        2(2, 1)               5
    3(3, 2)       4               6

*/
class Solution {
public:
    TreeNode* prev = NULL;
     void postorder(TreeNode* root) {
         if(root == NULL)
            return;
         
         postorder(root->right);
         postorder(root->left);
         
         root->right = prev;
         root->left = NULL;
         prev = root;
         
     }
    
    void flatten(TreeNode* root) {
        postorder(root);
    }
};