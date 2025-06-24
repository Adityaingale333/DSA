class Solution {
public:
    int solve(int i, vector<int>& nums, int target, vector<vector<int>>& t){
        if(i == nums.size()){
            return 1e9;
        }

        if(target == 0){
            return 0;
        }

        if(t[i][target] != -1){
            return t[i][target];
        }

        int notTake = solve(i+1, nums, target, t);

        int take = 1e9;
        if(nums[i] <= target){
            take = 1 + solve(i, nums, target-nums[i], t);
        }
        
        return t[i][target] = min(take, notTake); 
    }
    int numSquares(int n) {
        vector<int> nums;

        for(int i=1; i<=sqrt(n); i++){
            nums.push_back(i*i);
        }

        vector<vector<int>> t(nums.size(), vector<int>(n+1, -1));
        return solve(0, nums, n, t);
    }
};