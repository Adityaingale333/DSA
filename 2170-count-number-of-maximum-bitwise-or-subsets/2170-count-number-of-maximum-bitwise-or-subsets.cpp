class Solution {
public:
    int solve(int i, int maxOr, vector<int>& nums, int currOr){
        if(i == nums.size()){
            if(currOr == maxOr) return 1;
            return 0;
        }

        int take = solve(i+1, maxOr, nums, currOr | nums[i]);
        
        int notTake = solve(i+1, maxOr, nums, currOr);

        return take + notTake;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();

        int maxOr = 0;
        for(int i=0; i<n; i++){
            maxOr = maxOr | nums[i];
        }

        int currOr = 0;
        return solve(0, maxOr, nums, currOr);
    }
};