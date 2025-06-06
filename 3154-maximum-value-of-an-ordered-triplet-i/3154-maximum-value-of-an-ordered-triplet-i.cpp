class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> maxLeft(n,0);
        vector<int> maxRight(n,0);

        maxLeft[0] = nums[0];
        for(int i=1; i<n; i++){
            maxLeft[i] = max(maxLeft[i-1], nums[i]);
        }

        maxRight[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            maxRight[i] = max(maxRight[i+1], nums[i]);
        }

        long long ans = 0;
        for(int i=1; i<n-1; i++){
            long long val = (long long)(maxLeft[i-1] - nums[i]) * maxRight[i+1];
            ans = max(ans, val);
        }
        return ans;
    }
};