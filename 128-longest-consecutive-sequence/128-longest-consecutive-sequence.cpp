class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        set<int> numSet;
        
        for(int i=0;i<n;i++){
            numSet.insert(nums[i]);
        }
        
        int longStreak = 0;
        
        for(int i=0;i<n;i++){
            if(!numSet.count(nums[i]-1)){
                int currNum = nums[i];
                int currStreak = 1;
                
                while(numSet.count(currNum+1)){
                    currNum += 1;
                    currStreak += 1;
                }
                longStreak = max(longStreak, currStreak);
            } 
        }
        return longStreak;
        
    }
};