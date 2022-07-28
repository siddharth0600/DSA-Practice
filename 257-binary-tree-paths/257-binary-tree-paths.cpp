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
    void dfs(TreeNode* root, string &path, vector<string> &paths) {
        if(root == NULL) return;
        int val = root->val; 
        string s = to_string(val);
        string prev = path; // to store the previous version of path because we have to remove the nodes accordingly, once NULL is reach to construct the remaing paths
        if(path.empty()) path=s;
        else path+="->"+s;
        if(!root->left && !root->right) paths.push_back(path);
        dfs(root->left, path, paths);
        dfs(root->right, path, paths);
        path = prev; // after NULL end is reach we remove the nodes according to the recusion stack to construct the remaining paths
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector <string> paths;
        string path;
        dfs(root, path, paths);
        return paths;
    }
};