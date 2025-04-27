class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j=2;
        int count = 0;

        while(j<n){
            if(nums[i] + nums[j] == (float)nums[j-1]/2){
                count++;
            }
            i++;
            j++;
        }
        return count;
    }
};