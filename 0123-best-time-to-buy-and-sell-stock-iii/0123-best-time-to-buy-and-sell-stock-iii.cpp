class Solution {
public:
    /*int solve(int i, vector<int>& prices, int buy, int transaction, vector<vector<vector<int>>>& t){
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
    }*/
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
       /* //vector<vector<vector<int>>> t(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        // base case -> transaction == 2
        for(int i=0; i<n; i++){
            for(int buy=0; buy<=1; buy++){
                t[i][buy][2] = 0;
            }
        }
        // base case -> i == n
        for(int buy=0; buy<=1; buy++){
            for(int transaction=0; transaction<=2; transaction++){
                t[n][buy][transaction] = 0;
            }
        }*/

        // space optimize it, we will do something like memoization
        vector<vector<int>> after(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                for(int transaction=2-1; transaction>=0; transaction--){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[i] + after[0][transaction], after[1][transaction]);
                    }
                    else{
                        profit = max(prices[i] + after[1][transaction+1], after[0][transaction] );
                    }

                    curr[buy][transaction] = profit;
                }
            }
            after = curr;
        }
        return after[1][0] ;
    }
};