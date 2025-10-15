class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        int prev = 0;
        int curr = 1;

        int k = 0;

        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]){
                curr++;
            }
            else{
                prev = curr;
                curr = 1;
            }

            k = max(k, curr/2);
            k = max(k, min(prev, curr));
        }

        return k;
    }
};