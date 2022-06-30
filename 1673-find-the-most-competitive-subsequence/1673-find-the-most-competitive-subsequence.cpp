class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> MIS;
        int n=nums.size();
        int stackSize=1;
        
        MIS.push(nums[0]);
        for(int i=1;i<n;i++)
        {
            int left=n-i;
            // (k-stackSize<left) if no. of needed element to complete stack size k is less then the left element in the array then dont pop() anymore elements.
            while(!MIS.empty() and MIS.top()>nums[i] and k-stackSize<left) 
            {
                MIS.pop();
                stackSize--;
            }
            
            if(stackSize<k)  //if stack size is already reached the size of k dont push more undesirable elements .
            {
                MIS.push(nums[i]);
                stackSize++;
            } 
        }
        // after traversing all the array the satck size is of k and all the elements in stack is in Increasing order or in smallest lexicographically order.
        vector<int> res;
        while(!MIS.empty())
        {
            res.push_back(MIS.top());
            MIS.pop();
        }
        
        reverse(res.begin(),res.end());
        return res;
        
    }
};