class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         if(matrix.size()==0) return false;
        
       
//         int mid=0;
//         int iin,jin;
//         int n=matrix.size();
//         int m=matrix[0].size();
        
//         int i=0;
//         int j=n*m-1;
        
//         while(i<=j){
            
//             mid=(i+(j-i)/2);
//             iin = mid/n;
//             jin=mid%m;
//             if(matrix[iin][jin]==target) return true;
            
//             if(matrix[iin][jin]>target)
//                 j=mid-1;
//             else
//                 i=mid+1;
                    
            
//         }
//         return false;
        int row = matrix.size();
        int col = matrix[0].size();
        
        int start = 0;
        int end  = row*col-1;
        
        int mid = start + (end-start)/2;
        
        while(start<=end) {
            
            int element = matrix[mid/col][mid%col];
            
            if(element == target) {
                return 1;
            }
            
            if(element < target) {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
             mid = start + (end-start)/2;    
        }
        return 0;
    }
};