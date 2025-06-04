class Solution {
public:
    int solve(int i,int buy, int fee, vector<int>& prices, vector<vector<int>>& t){
        if(i >= prices.size()){
            return 0;
        }

        if(t[i][buy] != -1){
            return t[i][buy];
        }

        int profit = 0;
        if(buy){
            profit = max( -prices[i] + solve(i+1, 0, fee, prices, t), solve(i+1, 1, fee, prices, t) );
        }
        else{
            profit = max( prices[i] - fee + solve(i+1, 1, fee, prices, t), solve(i+1, 0, fee, prices, t) );
        }
        return t[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>> t(n, vector<int>(2, -1));
        return solve(0, 1, fee, prices, t);
    }
};