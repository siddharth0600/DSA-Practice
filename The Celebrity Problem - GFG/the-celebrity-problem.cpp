// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> s1;
        
        for(int i=0;i<n;i++){
            s1.push(i);
        }
        
        while(s1.size()!=1){
            int a=s1.top();
            s1.pop();
            
            int b=s1.top();
            s1.pop();
            
            if(M[a][b]==1) s1.push(b);
            else if(M[b][a]==1) s1.push(a);
        }
        
        int can=s1.top();
        for(int i=0;i<n;i++){
            if(M[can][i]==1) return -1;
        }
        
        for(int i=0;i<n;i++){
            if(i==can) continue;
            if(M[i][can]==0) return -1;
        }
        
        return can;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends