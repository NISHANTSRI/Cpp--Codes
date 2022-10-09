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
    void inorder(TreeNode* root,vector<int>& in){
        if(root == NULL) return;
        
        if(root->left) inorder(root->left,in);
        in.push_back(root->val);
        if(root->right) inorder(root->right,in);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> in;
        inorder(root,in);
        //for(auto it: in) cout << it << " ";
        
        unordered_map<int,int> mpp;
        
        for(int i=0;i<in.size();i++){
            if(mpp[k-in[i]] == 1) return true;
            mpp[in[i]] = 1;
        }
        
        return false;
    }
};