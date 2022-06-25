class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        int n=grid.size(),m=grid[0].size(),days=0,tot=0,cnt=0;
        queue<pair<int,int>> rot;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0)
                    tot++;
                if(grid[i][j]==2)
                    rot.push({i,j});
            } 
        
        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};
        
        while(!rot.empty()){
            int k=rot.size();
            cnt += k;
            
            while(k--){
                int x=rot.front().first; int y=rot.front().second;
                for(int i=0;i<4;i++){
                    int nx=x+dx[i]; int ny=y+dy[i];
                    if(nx<0 || ny<0 || nx>=n ||ny>=m || grid[nx][ny]!=1) continue;
                    grid[nx][ny]=2;
                    rot.push({nx,ny});
                }
                rot.pop();
            }
            
            if(!rot.empty()) days++;
            
            
        }
        
        return tot==cnt ? days : -1;
        
        
                
                
            
    }
}; 