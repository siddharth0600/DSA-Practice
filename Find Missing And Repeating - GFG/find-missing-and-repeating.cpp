// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
         int a=0,b=0;
        map<int,int> ans;
        for(int i=0;i<n;i++){
            ans[arr[i]]++;
        }
        for(int i=1;i<=n;i++){
            ans[i]++;
        }
        for(auto i:ans){
            if(i.second==1)
                b=i.first;
            if(i.second==3)
                a=i.first;
        }
        int *v = new int[2];
        v[0]=a;
        v[1]=b;
        return v;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends