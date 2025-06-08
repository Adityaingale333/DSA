class Solution {
public:
    long long solve(int i, int transaction, int state, int k, vector<int>& prices, vector<vector<vector<long long>>>& dp) {
        int n = prices.size();
        if (i >= n ){
            if(state != 0) return -1e9; // index khtm ho gaye aur state 0 nahi hai, matlb koi to transaction baki hai, isliye -infinity
            return 0;
        }

        if(transaction == k){
            return 0;
        }

        if (dp[i][transaction][state] != -1){
            return dp[i][transaction][state];
        }

        long long profit = 0;

        if (state == 0) {
            // kuch bhi kr skte hai, buy sell skip
            long long skip = solve(i+1, transaction, 0, k, prices, dp);
            long long buy = -prices[i] + solve(i+1, transaction, 1, k, prices, dp);
            long long shortSell = prices[i] + solve(i+1, transaction, 2, k, prices, dp);
            profit = max({skip, buy, shortSell});
        }
        else if (state == 1) {
            // buy kr liya hai ab -> ya to sell or hold
            long long sell = prices[i] + solve(i+1, transaction+1, 0, k, prices, dp); 
            long long hold = solve(i+1, transaction, 1, k, prices, dp);
            profit = max(sell, hold);
        }
        else {
            // sell kr dia hai ab -> ya to buy back or hold
            long long buyBack = -prices[i] + solve(i+1, transaction+1, 0, k, prices, dp); 
            long long hold = solve(i+1, transaction, 2, k, prices, dp);
            profit = max(buyBack, hold);
        }

        return dp[i][transaction][state] = profit;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        // 3states
        // 0. -> do anything
        // 1. -> can only sell or hold 
        // 2. -> can only buyback or hold
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(k+1, vector<long long>(3, -1)));
        return solve(0, 0, 0, k, prices, dp);
    }
};













