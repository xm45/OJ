/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root) {
            connect(root->left);
            connect(root->right);
            link(root->left,root->right);
        }
    }
    void link(TreeLinkNode *left, TreeLinkNode *right) {
        while(left) {
            left->next = right;
            left = left->right;
            right = right->left;
        }
    }
};