class Solution {
public:
    void solve(TreeNode*root, int target, int &currSum, vector<int>&temp, vector<vector<int>>&ans){
        if(root==NULL)
        return;

        //for leaf nodes only
        if(root->left==NULL && root->right==NULL){
            //include leaf node
            temp.push_back(root->val); 
            currSum+=root->val;
            if(currSum==target){
                ans.push_back(temp);
            }

            //exclude leaf node->backtrack
            temp.pop_back();
            currSum-=root->val;
            return;
        }
        //include curr node
        temp.push_back(root->val); 
        currSum+=root->val;

        solve(root->left, target, currSum, temp, ans);
        solve(root->right, target, currSum, temp, ans);

        //exclude leaf node->backtrack
        temp.pop_back();
        currSum-=root->val;

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        int sum=0;
        vector<int>temp;
        solve(root, targetSum, sum, temp, ans);
        return ans;
    }
};