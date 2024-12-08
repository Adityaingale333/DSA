class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int count_pre0 = 0;
        int windowsum = 0;
        int result = 0;

        while(r<n){
            windowsum += nums[r];

            while(l<r && (nums[l] == 0 || windowsum > goal)){
                if(nums[l] == 0){
                    count_pre0++;
                }
                else{
                    count_pre0 = 0;
                }
                windowsum = windowsum - nums[l];
                l++;
            }

            if(windowsum == goal) {result = result + 1 + count_pre0;}
            r++;
        }
        return result;
    }
};