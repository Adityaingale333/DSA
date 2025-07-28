class Solution {
public:
    int solve(int i, int maxOr, vector<int>& nums, int currOr, vector<vector<int>>& t){
        if(i == nums.size()){
            if(currOr == maxOr) return 1;
            return 0;
        }

        if(t[i][currOr] != -1){
            return t[i][currOr];
        }

        int take = solve(i+1, maxOr, nums, currOr | nums[i], t);
        
        int notTake = solve(i+1, maxOr, nums, currOr, t);

        return t[i][currOr] = take + notTake;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();

        int maxOr = 0;
        for(int i=0; i<n; i++){
            maxOr = maxOr | nums[i];
        }

        vector<vector<int>> t(n, vector<int>(maxOr+1, -1)); 
        int currOr = 0;
        return solve(0, maxOr, nums, currOr, t);
    }
};