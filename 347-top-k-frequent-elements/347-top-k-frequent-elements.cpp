class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> ma;
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(auto x:nums){
            ma[x]++;
        }
        
        for(auto x:ma){
            pq.push({x.second,x.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        vector<int> res;
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
        
        
    }
};