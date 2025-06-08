class Solution {
public:
    /*long long solve(int i, int transaction, int state, int k, vector<int>& prices, vector<vector<vector<long long>>>& dp) {
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
    }*/

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        // 3states
        // 0. -> do anything
        // 1. -> can only sell or hold 
        // 2. -> can only buyback or hold
        vector<vector<vector<long long>>> t(n+1, vector<vector<long long>>(k+1, vector<long long>(3, 0)));

        // jo base case 0 nahi hai, wahi likhunga, kyuki baki 0 se hi initialize kra hai maine
        for(int transaction=0; transaction<k+1; transaction++){
            for(int state = 1; state<=2; state++){
                t[n][transaction][state] = -1e9;
            }
        }

        for(int i=n-1; i>=0; i--){ // i == n pe profit 0 bcz out of bound index
            for(int transaction=k-1; transaction>=0; transaction--){ // transaction == k pe 0 bcz transaction khtm ho gaye
                for(int state=2; state>=0; state--){
                    long long profit = 0;

                    if (state == 0) {
                        // kuch bhi kr skte hai, buy sell skip
                        long long skip = t[i+1][transaction][0];
                        long long buy = -prices[i] + t[i+1][transaction][1];
                        long long shortSell = prices[i] + t[i+1][transaction][2];
                        profit = max({skip, buy, shortSell});
                    }
                    else if (state == 1) {
                        // buy kr liya hai ab -> ya to sell or hold
                        long long sell = prices[i] + t[i+1][transaction+1][0]; 
                        long long hold = t[i+1][transaction][1];
                        profit = max(sell, hold);
                    }
                    else {
                        // sell kr dia hai ab -> ya to buy back or hold
                        long long buyBack = -prices[i] + t[i+1][transaction+1][0]; 
                        long long hold = t[i+1][transaction][2];
                        profit = max(buyBack, hold);
                    }

                    t[i][transaction][state] = profit;
                }
            }
        }
        
        return t[0][0][0] ;
    }
};













