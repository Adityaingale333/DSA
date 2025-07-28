class Solution {
public:
    int solve(int i, int maxOr, vector<int>& nums, vector<int>& temp){
        if(i == nums.size()){
            int tempOr = 0;
            for(int i=0; i<temp.size(); i++){
                tempOr = tempOr | temp[i];
            }
            if(tempOr == maxOr) return 1;
            return 0;
        }

        temp.push_back(nums[i]);
        int take = solve(i+1, maxOr, nums, temp);
        temp.pop_back();

        int notTake = solve(i+1, maxOr, nums, temp);

        return take + notTake;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();

        int maxOr = 0;
        for(int i=0; i<n; i++){
            maxOr = maxOr | nums[i];
        }

        vector<int> temp;
        return solve(0, maxOr, nums, temp);
    }
};