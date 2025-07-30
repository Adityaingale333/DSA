class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int maxVal = 0;
        for(int i=0; i<n; i++){
            maxVal = max(maxVal, nums[i]);
        }

        int len = 0;
        int count = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == maxVal){
                count++;
            }
            else{
                count = 0;
            }

            len = max(len, count);
        }

        return len;
    }
};