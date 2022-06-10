class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();

	unordered_map<int,int> mpp;

	int sum = 0;
	mpp[0]  = 1;

	for(int num : nums){

		sum += num;

		int rem = sum%k;

		/** -ve reminder covert it to +ve reminder  */
		while(rem < 0) rem += k;

		if(mpp.find(rem) != mpp.end()) ans += mpp[rem];

		mpp[rem]++;
	}

	return ans;
    }
};