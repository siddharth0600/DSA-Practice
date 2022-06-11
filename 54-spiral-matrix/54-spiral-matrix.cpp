class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int minr=0,minc=0,maxr=n-1,maxc=m-1;
        
        int cnt=0;
        
        int tne=n*m;
        
        while(cnt<tne){
            for(int i=minc;i<=maxc && cnt<tne;i++){
                ans.push_back(matrix[minr][i]);
                cnt++;                    
            }
            minr++;
            
            for(int i=minr;i<=maxr && cnt<tne;i++){
                ans.push_back(matrix[i][maxc]);
                cnt++;
            }
            maxc--;
            
            for(int i=maxc;i>=minc && cnt<tne;i--){
                ans.push_back(matrix[maxr][i]);
                cnt++;
            }
            maxr--;
            
            for(int i=maxr;i>=minr && cnt<tne;i--){
                ans.push_back(matrix[i][minc]);
                cnt++;
            }
            minc++;
        }
        return ans;
    }
};