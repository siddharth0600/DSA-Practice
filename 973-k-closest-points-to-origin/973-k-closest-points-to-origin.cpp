class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        
        for(auto it : points){
            int x = it[0];
            int y = it[1];
            int distance = pow(x,2) + pow(y,2);
			
            pq.push({distance,it});
            
            while(pq.size() > k) pq.pop();
        }
        
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};