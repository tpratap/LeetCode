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
    vector<string> ans;
    void generate(TreeNode* root, string curr) {
        if(root == NULL)
            return;
        
        curr += to_string(root->val) + "->";
        
        if(root->left == NULL && root->right == NULL) {
            curr.pop_back();
            curr.pop_back();
            ans.push_back(curr);
            //curr = "";
            return;
        }
        
        
        generate(root->left, curr);
        generate(root->right, curr);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL)
            return {};
        
        string curr;
        generate(root, curr);
        
        return ans;
    }
};