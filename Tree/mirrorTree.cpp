class Solution {
public:
    bool solve(TreeNode*p, TreeNode*q){
        if(!p && !q)
        return true;

        if(p &&  q){
            return (p->val==q->val) && solve(p->left, q->right) && solve(p->right, q->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
         return solve(root->left, root->right);
    }
};