class Solution {
public:
    int solve(int i, int state, int transaction, vector<int>& prices, vector<vector<vector<int>>>& t){
        if(transaction == 0 || i >= prices.size()){
            if(state == 2) return -1e9;
            return 0;
        }

        if(t[i][state][transaction] != -1){
            return t[i][state][transaction];
        }

        int profit = 0;
        if(state == 1){
            int buy = -prices[i] + solve(i+1, 2, transaction-1, prices, t);
            int leave = solve(i+1, state, transaction, prices, t);
            profit = max(buy, leave);
        }
        else{
            int sell = prices[i] + solve(i+1, 1, transaction-1, prices, t);
            int leave = solve(i+1, state, transaction, prices, t);
            profit = max(sell, leave);
        }

        return t[i][state][transaction] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        // state 1 = only buy, either 1st day or sell kr diya hai
        // state 2 = only sell, buy kr liya hai

        vector<vector<vector<int>>> t(n, vector<vector<int>>(3, vector<int>(2*k+1, -1)));

        return solve(0, 1, 2*k, prices, t);
    }
};