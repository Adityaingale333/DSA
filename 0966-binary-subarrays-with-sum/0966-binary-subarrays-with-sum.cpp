class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        int l=0, r=0;
        int pre_zero = 0;
        int win_sum = 0;
        int count = 0;
        while(r<n){
           win_sum += nums[r];

            while(l<r && (nums[l] == 0 || win_sum > goal)){
                if(nums[l] == 0){
                    pre_zero++;
                }
                else{
                    pre_zero = 0;
                }
                win_sum -= nums[l];
                l++;
            }

            if(win_sum == goal){
                count += 1 + pre_zero;
            }
            r++;
        }
        return count;
    }
};