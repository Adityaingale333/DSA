class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int maxi = INT_MIN;

        for(int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);
        }

        int count = 0;
        long long ans = 0;
        while(j < n){
            if(nums[j] == maxi){
                count++;
            }

            while(count >= k){
                ans = ans + (n-j);
                if(nums[i] == maxi){
                    count--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};