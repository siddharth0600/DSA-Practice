class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxa=INT_MIN; //Return this not ans
        int ans;
        int i=0;
        int j=height.size()-1;
        
        while(i<j){
            ans=(j-i)*min(height[i],height[j]);
            maxa= max(maxa,ans);
            
            if(height[i]<height[j]) i++;
            else j--;
            
        }
        return maxa;
    }
};

