class Solution {
public:
// using multiplication bcz division is more costly operation
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i=1; i<n-1; i++){
            if(2*(nums[i-1]+nums[i+1]) == nums[i]){
                count++;
            }
        }
        return count;
    }
};