class Solution {
public:
    int solve(int i, int transaction, vector<int>& prices, vector<vector<int>>& t){
        if(transaction == 0){
            return 0;
        }
        if(i >= prices.size()){
            return 0;
        }

        if(t[i][transaction] != -1){
            return t[i][transaction];
        }

        int profit = 0;
        if(transaction%2 == 0){
            profit = max(-prices[i] + solve(i+1, transaction-1, prices, t), solve(i+1, transaction, prices, t));
        }
        else{
            profit = max(prices[i] + solve(i+1, transaction-1, prices, t), solve(i+1, transaction, prices, t));
        }
        return t[i][transaction] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> t(n, vector<int>((2*k)+1, -1));
        return solve(0, 2*k, prices, t);
    }
};