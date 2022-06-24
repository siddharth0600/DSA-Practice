class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
         int n=temp.size();
        vector<int> ans(n,-1);
        
        stack<int> s1;
       
        for(int i=n-1;i>=0;i--){
            
            while(!s1.empty() && temp[s1.top()]<=temp[i] ){
                s1.pop();
            }
            
            if(s1.empty())
                ans[i]=0;
            
            else
                ans[i]=s1.top()-i;
            
            s1.push(i);
        }
        
        return ans;
    }
};