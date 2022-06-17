class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        // Applied floyd warshall algorith in this first we have declared a distance 2d mmatrix then we have given distance to there own node i.e diagonal nodes of matrix as zero.
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        // then we have filled the given distance matrix with the give values of edges.
        for(auto v:edges){
            dist[v[0]][v[1]] = v[2];
            dist[v[1]][v[0]] = v[2];
        }
        // Now we have applied the condition of algorithm i.e if distance form i to j is greter then then distance of pivot from i to j i fit is then replace the value of the pivot in distance matrix.
        for(int k=0;k<n;k++) //pivot element
            for(int j=0;j<n;j++)
                for(int i=0;i<n;i++){
                    if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][k]+dist[k][j]<dist[i][j])
                      dist[i][j]=dist[i][k]+dist[k][j];
                }
            
        // Now for finding the answer find count for each city and if that count is less than city count replace ans with i and citycount with count
        int cityCount=INT_MAX;
        int ans;
        for(int i=0;i<n;i++){ //each city 
            int count=0;
            for(int j=0;j<n;j++){
                if(i!=j && dist[i][j]<=distanceThreshold)
                    count++;
            }
            if(count<=cityCount){
                ans=i;
                cityCount=count;
            }
        }
        return ans;
        
        
        
    }
};