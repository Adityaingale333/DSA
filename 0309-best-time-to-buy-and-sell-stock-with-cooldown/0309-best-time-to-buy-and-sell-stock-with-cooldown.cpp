class Solution {
public:
    /*int solve(int i, int buy, vector<int>& prices, vector<vector<int>>& t){
        if(i >= prices.size()){
            return 0;
        }

        if(t[i][buy] != -1){
            return t[i][buy];
        }

        int profit = 0;
        if(buy){
            profit = max( -prices[i] + solve(i+1, 0, prices, t), solve(i+1, 1, prices, t) );
        }
        else{
            profit = max( prices[i] + solve(i+2, 1, prices, t), solve(i+1, 0, prices, t) );
        }
        return t[i][buy] = profit;
    }*/
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> t(n+2, vector<int>(2, 0));

        for(int buy=0; buy<2; buy++){
            t[n+1][buy] = t[n][buy] = 0;
        }

        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<2; buy++){
                int profit = 0;
                if(buy){
                    profit = max( -prices[i] + t[i+1][0], t[i+1][1] );
                }
                else{
                    profit = max( prices[i] + t[i+2][1], t[i+1][0] );
                }
                t[i][buy] = profit;
            }
        }
        return t[0][1];
    }
};