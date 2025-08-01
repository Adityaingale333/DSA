class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int l=0, r=0;
        int count0 = 0;
        int ans = 0;

        while(r < n){
            if(nums[r] == 0){
                count0++;
            }

            while(count0 > k){
                if(nums[l] == 0){
                    count0--;
                }
                l++;
            }

            ans = max(ans, r-l+1);
            r++;
        }

        return ans;

    }
};