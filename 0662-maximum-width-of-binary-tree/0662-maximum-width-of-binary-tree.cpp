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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        
        long int ans = 0;
        
        while(!q.empty()){
            long int size = q.size();
            long int mmin = q.front().second;
            long int first,last;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front().first;
                long int cur = q.front().second - mmin;
                q.pop();
                
                if(i == 0) first = cur;
                if(i == size-1) last = cur;
                
                if(node->left) q.push({node->left,2*cur});
                if(node->right) q.push({node->right,2*cur+1});
            }
            
            ans = max(ans,last-first+1);
        }
        
        return ans;
    }
};