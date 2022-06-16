// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    void dfs(int node, stack<int> &stk,vector<int> &vis,vector<int> adj[]){
        vis[node]=1;
        
        for(auto itr: adj[node]){
            if(!vis[itr])
                dfs(itr,stk,vis,adj);
        }
        
        stk.push(node);
    }
    
    void revDfs(int node,vector<int> &vis,vector<int> transpose[]){
        vis[node]=1;
        
        for(auto itr:transpose[node]){
            if(!vis[itr])
                revDfs(itr,vis,transpose);
        }
    }
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
       vector<int> vis(V,0);
       stack<int> stk;
       
       for(int i=0;i<V;i++)
        if(!vis[i])
            dfs(i,stk,vis,adj);
            
       vector<int> transpose[V];
       
       for(int i=0;i<V;i++){
           vis[i]=0;
           for(auto itr:adj[i])
            transpose[itr].push_back(i);
       }
       int cnt=0;
       while(!stk.empty()){
           int node=stk.top();
           stk.pop();
           if(!vis[node]){
               revDfs(node,vis,transpose);
               cnt++;
           }
       }
       return cnt;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends