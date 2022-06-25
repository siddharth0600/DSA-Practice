class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++){
            // As the window move on, element nums[left-k] will be outdated.
            if(!dq.empty() && dq.front()==i-k) dq.pop_front();
            // Now we are ready to push our new element nums[left]'s index into the queue.
           // But before that, we should clear elements which is smaller then nums[left].
           // Why? Because if nums[left] is bigger then nums[i], 
           // there will be no way for nums[i] be selected as the max number in range (left-k, left]
            while(!dq.empty() && nums[dq.back()]<=nums[i])
                dq.pop_back();
            // Now push the index into our queue.
            dq.push_back(i);
            // Okay, now nums[queue.front()] mush be the max number in range (left-k, left] 
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};