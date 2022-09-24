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
    
    void solve(TreeNode* root, int t, vector<vector<int>> &ans,vector<int> &temp){
        if(root == NULL) return ;
        
        if(root->right == NULL and root->left == NULL and root->val-t == 0){
            temp.push_back(root->val);
            ans.push_back(temp);
            temp.pop_back();
        }
        
        if(root->left){
            temp.push_back(root->val);
            solve(root->left,t-root->val,ans,temp);
            temp.pop_back();
        }
        
        //temp.pop_back();
        
        if(root->right){
            temp.push_back(root->val);
            solve(root->right,t-root->val,ans,temp);
            temp.pop_back();
        }
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root,targetSum,ans,temp);
        
        return ans;
    }
};