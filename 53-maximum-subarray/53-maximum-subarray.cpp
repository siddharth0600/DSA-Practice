class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int mx=INT_MIN;
        
        for(auto itr:nums){
            sum += itr;
            mx = max(sum,mx);
            if(sum<0) sum=0;
        }
        return mx;
    }
};