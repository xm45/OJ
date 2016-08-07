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
            TreeLinkNode *next = root->next;
            while(next) {
                if(next->left) {
                    next = next->left;
                    break;
                }
                if(next->right) {
                    next = next->right;
                    break;
                }
                next = next->next;
            }
            if(root->right) {
                root->right->next = next;
                if(root->left)
                    root->left->next = root->right;
            }
            else if(root->left) {
                root->left->next = next;
            }
            connect(root->right);
            connect(root->left);
        }
    }
};