class Solution {
    
    void helper(int ind,vector<vector<int>> &ans,vector<int> &ds,vector<int>& can, int tar){
        if(ind==can.size()){
            if(tar==0){
                ans.push_back(ds);
            }
            return;
        }
        
        if(can[ind]<=tar){
            ds.push_back(can[ind]);
            helper(ind,ans,ds,can,tar-can[ind]);
            ds.pop_back();
        }
        
        helper(ind+1,ans,ds,can,tar);
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& can, int tar) {
        vector<vector<int>> ans;
        vector<int> ds;
        helper(0,ans,ds,can,tar);
        return ans;
    }
};