class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int minElement = nums[0];
        int ans = -1;

        for(int i=1; i<n; i++){
            if(nums[i] > minElement){
                ans = max(ans, nums[i]-minElement);
            }
            else{
                minElement = nums[i];
            }
        }

        return ans;
    }
};