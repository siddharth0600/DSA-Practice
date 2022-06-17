// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    private:
    bool chkCycle(int node,vector<int> adj[],vector<int> &vis,vector<int> &dfsVis){
        vis[node]=1;
        dfsVis[node]=1;
        
        for(auto itr:adj[node]){
            if(!vis[itr]){
            if(chkCycle(itr,adj,vis,dfsVis)) return true;}
         else if(dfsVis[itr]) return true;
        }
        dfsVis[node]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> dfsVis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i])
                if(chkCycle(i,adj,vis,dfsVis)) return true;
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends