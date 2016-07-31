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
    TreeNode *bad1,*bad2,*pre;
    void findBad(TreeNode* root){
        if(root == NULL)
            return;
        findBad(root->left);
        if(pre != NULL){
            if(pre->val > root->val){
                if(bad1 == NULL){
                    bad1 = pre;
                    bad2 = root;
                }
                else
                    bad2 = root;
            }
        }
        pre = root;
        findBad(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        bad1=bad2=pre=NULL;
        findBad(root);
        if(bad1 != NULL && bad2 != NULL){
            int temp = bad1->val;
            bad1->val = bad2->val;
            bad2->val = temp;
        }
    }
};