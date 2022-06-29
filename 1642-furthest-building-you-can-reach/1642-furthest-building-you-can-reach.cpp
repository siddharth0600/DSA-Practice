class Solution {
public:
    int furthestBuilding(vector<int>& v, int b, int l) {
        
        priority_queue<int> pq;
        int i;
        for(i=0;i<v.size()-1;i++){
            if(v[i+1]<=v[i]) continue;
            int d=v[i+1]-v[i];
            if(d<=b){
                 b -= d;
                pq.push(d);
            }
            else if(l>0){
                if(pq.size()>0){
                    int x=pq.top();
                    if(x>d){
                        b += x;
                        pq.pop();
                        pq.push(d);
                        b -= d;
                    }
                }
                l--;
            }
            else break;
            
            
        }
        return i;
    }
};