// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    // 
    // struct meeting{
    //     int start;
    //     int end;
    //     int pos;
    // };
    
    // bool comp(struct meeting m1,meeting m2){
    //     if(m1.end < m2.end) return true;
    //     else if(m1.end > m2.end) return false;
    //     else if(m1.pos < m2.pos) return true;
    //     return false;
    // }
    
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    // int maxMeetings(int s[], int e[], int n){
    
        // Your code here
        // struct meeting meet[n];
        
        // for(int i=0;i<n;i++){
        //     meet[i].start = s[i],meet[i].end = e[i],meet[i].pos=i+1;
        // }
        
        // sort(meet, meet+n, comp());
        
        // vector<int> answer;
        
        // int limit = meet[0].end;
        // answer.push_back(meet[0].pos);
        
        // for(int i=1;i<n;i++){
        //     if(meet[i].start>limit){
        //         limit = meet[i].end;
        //         answer.push_back(meet[i].pos);
        //     }
         int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>a;
        for(int i=0;i<n;i++)a.push_back({end[i],start[i]});
        sort(a.begin(),a.end());
        int cnt=1;
        int endt=a[0].first;
        for(int i=1;i<n;i++){
            if(a[i].second>endt){
                cnt++;
                endt=a[i].first;
            }
        }
        return cnt;
    }
        
        
    // }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends