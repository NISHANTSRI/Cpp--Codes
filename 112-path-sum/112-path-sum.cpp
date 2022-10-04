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
    
    bool solve(TreeNode* root, int target){
        if(root == NULL) return false;
        
        if(root->left == NULL and root->right == NULL){
            if(root->val == target) return true;
            else return false;
        }
        
        bool res1,res2;
        if(root->left) res1 = solve(root->left,target-root->val);
        if(root->right) res2 = solve(root->right,target-root->val);
        
        return res1 or res2;
    }
    
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,targetSum);
    }
};