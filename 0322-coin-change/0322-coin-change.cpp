class Solution {
public:
    int solve(int i, int amount, vector<int>& coins,  vector<vector<int>>& t){
        if(i == 0){
            if(amount % coins[0] == 0) return amount/coins[0];
            return 1e9;
        }

        if(t[i][amount] != -1){
            return t[i][amount];
        }

        int notTake = solve(i-1, amount, coins, t);

        int take = INT_MAX;
        if(coins[i] <= amount){
            take = 1 + solve(i, amount-coins[i], coins, t);
        }
        return t[i][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> t(n, vector<int>(amount+1, -1));

        int ans = solve(n-1, amount, coins, t);
        if(ans >= 1e9) return -1;
        return ans;
    }
};