class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1); // dp[i] stores the length of the LIS ending at index i
        vector<int> count(n, 1); // count[i] stores the number of LIS of maximum length ending at index i
        int len = 0; // Maximum length of the LIS

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                // If we found a longer subsequence ending at i
                if(nums[i] > nums[j] && dp[j]+1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    count[i] = count[j]; // Reset the count to the number of ways to form subsequences ending at j
                }
                else if(nums[i] > nums[j] && dp[j]+1 == dp[i]){ // If we found another subsequence of the same length ending at i
                    
                    // Add the number of ways to form subsequences ending at j
                    count[i] = count[i] + count[j];
                }
            }   
            len = max(len, dp[i]);
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            if(dp[i] == len){
                ans = ans + count[i]; // Sum up the number of LIS with the maximum length
            }
        }
        return ans;
    }
};