// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void helper(int ind,int sum,vector<int> &ans,int N,vector<int> arr){
        if(ind==N){
            ans.push_back(sum);
            return;
        }
        
        helper(ind+1,sum+arr[ind],ans,N,arr);
        helper(ind+1,sum,ans,N,arr);
        
        return;
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        helper(0,0,ans,N,arr);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends