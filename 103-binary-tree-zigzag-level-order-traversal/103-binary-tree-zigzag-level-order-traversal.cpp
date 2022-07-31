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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> lev;
        
        if(root==NULL)
            return ans;
        
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        
        s1.push(root);
        
        while(!s1.empty() || !s2.empty()){
            
            while(!s1.empty()){
                
                TreeNode* temp = s1.top();
                s1.pop();
                lev.push_back(temp->val);
                if(temp->left!=NULL) s2.push(temp->left);
                if(temp->right!=NULL) s2.push(temp->right);
                if(s1.empty()){
                    ans.push_back(lev);
                    lev.clear();
                }
                
                
            }
            while(lev.size()!=0){
                lev.pop_back();
            }
            while(!s2.empty()){
                
                TreeNode* temp = s2.top();
                s2.pop();
                lev.push_back(temp->val);
                if(temp->right!=NULL) s1.push(temp->right);
                if(temp->left!=NULL) s1.push(temp->left);
                
                if(s2.empty()){
                    ans.push_back(lev);
                    lev.clear();
                }
                
                
            }
            
        }
        return ans;
    }
};