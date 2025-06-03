class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> t(n+1, vector<int>(2, 0)); // buy.size() == 2, 0 and 1, 0 means cannot buy
       
        t[n][0] = t[n][1] = 0;
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[i]+t[i+1][0], t[i+1][1]);
                }
                else{
                    profit = max(prices[i]+t[i+1][1], t[i+1][0]);
                }
                t[i][buy] = profit;
            }
        }
        return t[0][1] ;
    }
};