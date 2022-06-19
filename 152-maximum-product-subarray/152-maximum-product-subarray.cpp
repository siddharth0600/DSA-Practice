class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int nmax=nums[0];
        int nmin=nums[0];
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0) swap(nmax,nmin);
            nmax = max(nums[i],nmax*nums[i]);
            nmin = min(nums[i],nmin*nums[i]);
            ans=max(nmax,ans);
        }
        
        return ans;
        
    }
};