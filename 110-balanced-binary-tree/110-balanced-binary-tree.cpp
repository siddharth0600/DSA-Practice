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
    int heightBT(TreeNode *root){
        if(root==NULL)
            return 0;
            
        return 1+max(heightBT(root->left),heightBT(root->right));
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        return true;
        
        if(!isBalanced(root->left) || !isBalanced(root->right))
        return false;
        
        if(abs(heightBT(root->left)-heightBT(root->right))<=1)
        return true;
        
        return false;
    }
};