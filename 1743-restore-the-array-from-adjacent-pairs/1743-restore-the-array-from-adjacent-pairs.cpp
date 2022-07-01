class Solution {
public:
    void dfs(map<int,vector<int>>&m,set<int> &v, int a, vector<int> &ans){
        if(v.find(a)!=v.end()) return;
        ans.push_back(a);
        v.insert(a);
        for(auto x:m[a]) dfs(m,v,x,ans);
    }
    
    vector<int> restoreArray(vector<vector<int>>& A) {
        map<int,vector<int>> m;
        for(auto a:A){
            m[a[0]].push_back(a[1]);
            m[a[1]].push_back(a[0]);
        } //First we have created a graph from the adjacent pairs
        int head;
        for(auto a:m){
            if(a.second.size()==1) head=a.first; //for the head element the the elemtns attached will be only one thus its size will be 1, head can be first element or the last elemement
        }
        set<int> v; //Visisted elemtns
        vector<int> ans;
        dfs(m,v,head,ans);
        return ans;
    }
};