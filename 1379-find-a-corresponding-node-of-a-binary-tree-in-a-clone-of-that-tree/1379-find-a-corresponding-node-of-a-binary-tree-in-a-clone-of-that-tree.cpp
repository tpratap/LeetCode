/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({original, cloned});
        while(!q.empty()) {
            TreeNode* node1 = q.front().first;
            TreeNode* node2 = q.front().second;
            q.pop();
            if(node1 == target)
                return node2;
            if(node1->left) {
                q.push({node1->left, node2->left});
            }
            if(node2->right) {
                q.push({node1->right, node2->right});
            }
        }
        return NULL;
    }
};