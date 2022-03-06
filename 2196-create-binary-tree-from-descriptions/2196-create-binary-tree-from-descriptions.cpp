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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
       unordered_map<int, pair<TreeNode*, bool>> mp;
       for(auto &node : descriptions) {
           int parent = node[0];
           int child = node[1];
           int left = node[2];
           TreeNode *parentNode, *childNode;
           if(mp.find(parent) == mp.end()) {
              parentNode = new TreeNode(parent);
               mp[parent] = {parentNode,true};
           }
           if(mp.find(child) == mp.end()) {
               childNode = new TreeNode(child);
               mp[child] = {childNode,false};
           } else {
               mp[child].second = false;
           }
           if(left == 1) {
               mp[parent].first->left = mp[child].first;
           } else {
               mp[parent].first->right = mp[child].first;
           }
       }
       
        TreeNode* root = NULL;
       
        for(auto &node: mp) {
            cout<<node.second.first->val<<" ";
            if(node.second.second == true) {
                root = node.second.first; 
            }
        }
        cout<<root->val<<" ";
        return root;
    }
};