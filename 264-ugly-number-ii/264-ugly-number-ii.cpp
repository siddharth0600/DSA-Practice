class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        
        int p2=0,p3=0,p5=0;
        
        for(int i=1;i<n;i++){
            
            int twomultiple = dp[p2]*2;
            int threemultiple = dp[p3]*3;
            int fivemultiple = dp[p5]*5;
            
            dp[i]=min(twomultiple,min(threemultiple,fivemultiple));
            
            if(dp[i]==twomultiple) p2++;
            if(dp[i]==threemultiple) p3++;
            if(dp[i]==fivemultiple) p5++;
            
        }
        
        return dp[n-1];
    }
};