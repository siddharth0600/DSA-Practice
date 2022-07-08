class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int tarRow=0;
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int i=0;i<matrix.size();i++){
            if(target>=matrix[i][0] && target<=matrix[i][m-1]){
                tarRow=i;
                break;
            }
        }
        
        for(int j=0;j<m;j++){
            if(matrix[tarRow][j]==target){
                return true;
            }    
        }
        return false;
        
    }
};