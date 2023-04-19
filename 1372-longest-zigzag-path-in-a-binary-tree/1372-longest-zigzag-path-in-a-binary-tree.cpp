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
    int maxLen = 0;
    
    void f(TreeNode* root,int currLen,int dir){
        if(!root) return;
        
        maxLen = max(maxLen,currLen);
        
        if(dir == 0){
            f(root->right,currLen+1,1);
            f(root->left,1,0);
        }
        
        if(dir == 1){
            f(root->left,currLen+1,0);
            f(root->right,1,1);
        }
    }
    
public:
    int longestZigZag(TreeNode* root) {
        f(root,0,0);
        f(root,0,1);
        
        return maxLen;
    }
};