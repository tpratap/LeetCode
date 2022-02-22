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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int sum = 0;
        while(!q.empty()) {
            TreeNode* src = q.front();
            q.pop();
            if(q.empty())
                break;
            if(src == NULL) {
                q.push(NULL);
                sum = 0;
            }
            else {
                sum += src->val;
                if(src->left) {
                    q.push(src->left);
                }
                if(src->right) {
                    q.push(src->right);
                }
            }
        }
        return sum;
    }
};