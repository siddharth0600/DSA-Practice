class Solution {
public:
    int helper(vector<int>& coins, int target,int index,vector<vector<int>> &dp){
        
        if(index==0){
            if(target%coins[index]==0) return target/coins[index];
            else return 1e9;
        }
        
        if(dp[index][target]!=-1) return dp[index][target];
        
        int notTake = helper(coins,target,index-1,dp);
        // here we have passed index-1 because in this case we are not even using the denomination
        int take=INT_MAX;
        if(coins[index]<=target) take=1+helper(coins,target-coins[index],index,dp);
        // In the above if condition we have passed index not index-1 because in the question it was given that we can use one denomination multiple times
        return dp[index][target]=min(take,notTake);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        
        int ans= helper(coins,amount,coins.size()-1,dp);
        if(ans>=1e9) return -1;
        else return ans;
        
    }
};