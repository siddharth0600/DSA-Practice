// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	     int n=grid.size(),m=grid[0].size();
    queue<pair<int,int>>q1;
    vector<vector<int>>a(n,vector<int>(m,INT_MAX));
	    
	    for(int i=0;i<n;i++)
	        for(int j=0;j<m;j++)
	            if(grid[i][j]==1){
	                a[i][j]=0;
	                q1.push({i,j});
	            }
	                
	   
	   while(!q1.empty()){
	       int i=q1.front().first;
	       int j=q1.front().second;
	       
	       if(i-1>=0 && a[i][j]+1<a[i-1][j]){
	           a[i-1][j]=a[i][j]+1;
	           q1.push({i-1,j});
	       }
	       if(i+1<n && a[i][j]+1<a[i+1][j]){
	           a[i+1][j]=a[i][j]+1;
	           q1.push({i+1,j});
	       }
	       if(j-1>=0 && a[i][j]+1<a[i][j-1]){
	           a[i][j-1]=a[i][j]+1;
	           q1.push({i,j-1});
	       }
	       if(j+1<m && a[i][j]+1<a[i][j+1]){
	           a[i][j+1]=a[i][j]+1;
	           q1.push({i,j+1});
	       }
	       q1.pop();
	   }
	   
	   return a;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends