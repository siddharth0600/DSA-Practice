class Solution {
public:
    vector<vector<vector<int>>> dp;
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.resize(m+1,vector<vector<int>>(n+1,vector<int>(strs.size(),-1)));
        return findMax(strs,m,n,0);
    }
    int findMax(vector<string>& strs, int m, int n,int index){
        if(index==strs.size()) return 0;
        if(dp[m][n][index]!=-1) return dp[m][n][index];
        
        int countZeroes=count(strs[index].begin(),strs[index].end(),'0');
        int countOnes=strs[index].size()-countZeroes;
        
        if(m-countZeroes>=0 && n-countOnes>=0)
            return dp[m][n][index]=max(1+findMax(strs,m-countZeroes,n-countOnes,index+1),findMax(strs,m,n,index+1));
        
        return dp[m][n][index]=findMax(strs,m,n,index+1);
    }
};