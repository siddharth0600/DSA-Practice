class Solution {
public:
    
    int helper(int index,vector<int> &nums,vector<int> &dp){
        if(index==0)
            return nums[0];
        if(index<0)
            return 0;
        
        if(dp[index]!=-1) return dp[index];
        
        int pick = nums[index] + helper(index-2,nums,dp);
        int notPick = helper(index-1,nums,dp);
        
        return dp[index]=max(pick,notPick);
        
    }
    
    int rob(vector<int>& nums) {
        
        vector<int> dp(nums.size(),-1);
        
        return helper(nums.size()-1,nums,dp);
    }
};