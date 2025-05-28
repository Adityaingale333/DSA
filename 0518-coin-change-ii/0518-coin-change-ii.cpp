class Solution {
public:
    int solve(int i, int amount, vector<int>& nums, vector<vector<int>>& t){
        if(amount == 0){
            return 1;
        }
        if(i == 0){
            if(amount % nums[0] == 0) return 1;
            return 0;
        }

        if(t[i][amount] != -1){
            return t[i][amount];
        }

        int notTake = solve(i-1, amount, nums, t);

        int take = 0;
        if(nums[i] <= amount){
            take = solve(i, amount-nums[i], nums, t);
        }
        return t[i][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
       int n = coins.size();
       vector<vector<int>> t(n, vector<int>(amount+1, -1));
       return solve(n-1, amount, coins, t); 
    }
};