// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

bool possiblecol(int color, int node, bool gr[101][101], vector<int> col,int n){
        for(int i = 0;i<n;i++){
            if(i!=node && gr[node][i]==1 && col[i]==color)
                return false;
        }
        return true;
    }

bool solve(int node, int n, bool gr[101][101], vector<int> &col, int m){
        if(n==node)
            return true;
            
        for(int i=1;i<=m;i++){
            if(possiblecol(i,node,gr,col,n)){
                col[node] = i;
                if(solve(node+1,n,gr,col,m))
                    return true;
                
                col[node] = 0;
            }
        }
        
        return false;
    }
    
    
  

bool graphColoring(bool gr[101][101], int m, int n) {
    vector<int> adj[n];
    
    int i,j;
 
        
        vector<int> color(n);
        
        return solve(0,n,gr,color,m);
    }

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends