// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int func(vector<int> &dp,int n, int x, int y, int z){
        if(n==0) return 0;       //Base Condition
        if(n<0) return INT_MIN;  //Base Condition
        if(dp[n]!=-1) return dp[n]; //memoization
        int t1=func(dp,n-x,x,y,z);    //recursion
        int t2=func(dp,n-y,x,y,z);    //recursion
        int t3=func(dp,n-z,x,y,z);    //recursion
        return dp[n]=1+max(t1,max(t2,t3));
    }
int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int>dp(n+1,-1);
        int res=func(dp,n,x,y,z);
        return res<0?0:res;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends