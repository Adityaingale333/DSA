class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxValue = 0;
        int result = 0;
        int streak = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] > maxValue){
                maxValue = nums[i];
                result = 0;
                streak = 0;
            }

            if(nums[i] == maxValue){
                streak++;
            }
            else{
                streak = 0;
            }

            result = max(result, streak);
        }
        return result;
    }
};