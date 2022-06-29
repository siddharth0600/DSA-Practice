class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int> pq;
        
        for(auto i:nums){
            pq.push(i);
        }
        int n=k-1;
        while(n--){
            pq.pop();
        }
        
        return pq.top();
        
        
    }
};