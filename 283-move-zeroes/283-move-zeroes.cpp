class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0,r=0;
        
        int n=nums.size();
        
        if(n==0 || n==1)
            return;
        
        while(r<n){
            if(nums[r]==0){
                r++;
            } else {
                swap(nums[r],nums[l]);
                r++;
                l++;
            }
        }
    }
};