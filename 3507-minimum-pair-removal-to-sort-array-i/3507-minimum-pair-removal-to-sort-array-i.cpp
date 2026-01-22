class Solution {
public:
    int minPairSum(vector<int>& nums){
        int minSum = INT_MAX;
        int idx = -1;

        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] + nums[i+1] < minSum){
                idx = i;
                minSum = nums[i] + nums[i+1];
            }
        }
        return idx;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int operation = 0;

        while(!is_sorted(nums.begin(), nums.end())){
            int idx = minPairSum(nums);

            nums[idx] = nums[idx] + nums[idx+1];
            nums.erase(nums.begin() + idx + 1);

            operation++;
        }

        return operation;
    }
};