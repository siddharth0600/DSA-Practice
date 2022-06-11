class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> prefix(n+1);
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + cardPoints[i];
        }        

        int answer = 0;
        for (int i = 0; i <= k; i++) {
            int point = prefix[n] - (prefix[n-k+i] - prefix[i]);
            answer = max(answer, point);
        }
        return answer;
    }
};