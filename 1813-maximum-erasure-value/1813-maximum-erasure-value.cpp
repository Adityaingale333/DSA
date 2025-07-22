class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> freq;

        int l=0, r=0;
        int currSum = 0;
        int ans = 0;

        while(r < n){
            freq[nums[r]]++;
            currSum = currSum + nums[r];

            while(l < r && freq[nums[r]] > 1){
                currSum = currSum - nums[l];
                freq[nums[l]]--;
                l++;
            }

            ans = max(ans, currSum);
            r++;
        }

        return ans;
    }
};