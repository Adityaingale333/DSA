class Solution {
public:
    int solve(int i, vector<int>& prices, int buy, int transaction, vector<vector<vector<int>>>& t){
        if(transaction == 2){
            return 0;
        }
        if(i >= prices.size()){
            return 0;
        }

        if(t[i][buy][transaction] != -1){
            return t[i][buy][transaction];
        }

        int profit = 0;
        if(buy){
            profit = max(-prices[i] + solve(i+1, prices, 0, transaction, t), solve(i+1, prices, 1, transaction, t) );
        }
        else{
            profit = max(prices[i] + solve(i+1, prices, 1, transaction+1, t), solve(i+1, prices, 0, transaction, t) );
        }

        return t[i][buy][transaction] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> t(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, prices, 1, 0, t);
    }
};