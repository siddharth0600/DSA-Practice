class Solution {
public:
    
    void flood_fill(int i,int j,vector<vector<int>>& grid,vector<pair<int,int>> &r){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size() || grid[i][j]==0)
            return;
        
        grid[i][j]=0;
        r.push_back(make_pair(i,j));
        flood_fill(i+1,j,grid,r);
        flood_fill(i-1,j,grid,r);
        flood_fill(i,j+1,grid,r);
        flood_fill(i,j-1,grid,r);
        
        return;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int count=0;
        vector<pair<int,int>> x;
        vector<pair<int,int>> y;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    count++;
                    if(count==1){
                        flood_fill(i,j,grid,x);
                    } 
                    if(count==2){
                        flood_fill(i,j,grid,y);
                    }
                }
            }
        }
        //Min Distance
        int min_dist = INT_MAX;
        for(int i=0; i<x.size(); i++)
        {
            for(int j=0; j<y.size(); j++)
            {
                int dist = abs(x[i].first - y[j].first) + abs(x[i].second - y[j].second) - 1;
                if(dist < min_dist)
                    min_dist = dist;
            }
        }
        return min_dist;
    }
};