class Solution {
public:
void inorder(TreeNode* root, int& temp){
        if(!root) return;
        inorder(root->right, temp);
        //
        root->val+=temp;
        temp=root->val;
        inorder(root->left,temp);
    }

    TreeNode* convertBST(TreeNode* root) {
         int temp=0;
        inorder(root,temp);
        return root;
    }
};