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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        TreeNode* now = root;
        while(now || !s.empty()) {
            while(now){
                s.push(now);
                now = now->left;
            }
            if(!s.empty()) {
                now = s.top();
                s.pop();
                ans.push_back(now->val);
                now = now->right;
            }
        }
        return ans;
    }
};