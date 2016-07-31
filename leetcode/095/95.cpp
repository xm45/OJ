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
    vector<TreeNode*> generateTrees(int n) {
        if(n > 0)
            return make(1,n);
        else
            return vector<TreeNode*>();
    }
    vector<TreeNode*> make(int l,int r) {
        vector<TreeNode*> ret;
        if(l>r)
        {
            ret.push_back(NULL);
            return ret;
        }
        for(int k = l; k <= r; k ++) {
            vector<TreeNode*> lchild = make(l,k-1);
            vector<TreeNode*> rchild = make(k+1,r);
            int llen = lchild.size(),rlen = rchild.size();
            for(int i = 0; i < llen; i ++)
                for(int j = 0; j < rlen; j ++) {
                    TreeNode* t = new TreeNode(k);
                    t->left = lchild[i];
                    t->right = rchild[j];
                    ret.push_back(t);
                }
        }
        return ret;
    }
};