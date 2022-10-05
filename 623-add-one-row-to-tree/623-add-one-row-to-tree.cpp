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
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) return new TreeNode(val,root,NULL);
        add(root, val, 1, depth);
        return root;
    }
    void add(TreeNode* root, int val,int h, int depth){
        if(!root) return;
        if(h == depth-1){
            root->left  =  new TreeNode(val, root->left,  NULL);
            root->right =  new TreeNode(val, NULL, root->right);
            return;
        }
        add(root->left , val, h+1, depth);
        add(root->right, val, h+1, depth);
    }
};