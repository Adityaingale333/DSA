class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> cumSum(n, 0);
        cumSum[0] = nums[0];

        for(int i=1; i<n; i++){
            cumSum[i] = cumSum[i-1] + nums[i];
        }

        vector<int> mp(10001, -1); // element -> index

        int l=0, r=0;
        int ans = 0;

        while(r < n){
            l = max(l, mp[nums[r]] + 1);

            mp[nums[r]] = r;
            
            int sum_r = cumSum[r];
            int sum_l = (l-1 < 0) ? 0 : cumSum[l-1];

            ans = max(ans, sum_r - sum_l);

            r++;
        }

        return ans;
    }
};