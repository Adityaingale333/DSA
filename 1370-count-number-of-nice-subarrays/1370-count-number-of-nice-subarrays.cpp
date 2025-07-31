class Solution {
public:
    // we can also solve this using leetcode 560, subarray sum equals k
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp; // freq of odd numbers -> how many times we have seen these odd numbers
                                    // 0 -> 1,  1 -> 1,  2 -> 3,  3 -> 1
        
        mp[0] = 1; // before the start of the array we have seen 0 odd numbers, 1 time

        int l=0, r=0;
        int oddCount = 0;
        int ans = 0;

        while(r < n){
            if(nums[r] % 2 == 1){
                oddCount++;
            }

            int remOddCount = oddCount - k;

            if(mp.count(remOddCount)){
                ans = ans + mp[remOddCount];
            }

            mp[oddCount]++;
            r++;
        }

        return ans;
    }
};