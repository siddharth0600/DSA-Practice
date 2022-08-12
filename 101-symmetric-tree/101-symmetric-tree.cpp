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
   bool similar(TreeNode* left , TreeNode* right){
    if( !left && !right) //if both null
        return true;
    
    if(left && !right) // if one null
        return false;
    
    if( !left && right)
        return false;
    
    if(left->val != right->val)  // if values are not equal
        return false;
    
    return similar(left->left , right->right) && similar(left->right , right->left);
    
}

bool isSymmetric(TreeNode* root) {
    if(root == NULL)
        return true;
    
    return similar(root->left,root->right);
}
};