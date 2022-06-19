class Solution {
public:
    vector<int> countBits(int n) {
        // Bruteforce approach O(n^2) time.
//         vector<int> ans(n+1,0);
        
//         for(int i=0;i<=n;i++){
//             int num =i;
            
//             int count=0;
            
//             while(num){
//                 count += num%2;
//                 num /=2;
                
//             }
//             ans[i]=count;
//         }
//         return ans;
        
        vector<int> ans(n+1,0);
        for(int i=0;i<=n;i++){
            
            if(i%2==0) 
                ans[i] = ans[i/2];//For even nos
            else
                ans[i] = ans[i/2] +1; // For odd nos
        }
        
        return ans;
    }
};