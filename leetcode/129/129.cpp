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
    int sumNumbers(TreeNode* root) {
        return getSum(root,0);
    }
    int getSum(TreeNode* root, int now) {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return now*10 + root->val;
        return getSum(root->left,now*10+root->val) + getSum(root->right,now*10+root->val);
    }
};