class Solution {
public:
  /*int solve(int i, int transaction, vector<int>& prices, vector<vector<int>>& t){
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
    }*/
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

       /* vector<vector<int>> t(n+1, vector<int>((2*k)+1, 0));

        for(int i=0; i<n; i++){
            t[i][0] = 0;
        }
        for(int transaction=0; transaction<(2*k)+1; transaction++){
            t[n][transaction] = 0;
        }*/

        // space optimization, we will use vector
        vector<int> after((2*k)+1, 0);
        vector<int> curr((2*k)+1, 0);

        for(int i=0; i<n; i++){
            after[0] = 0;
        }
        for(int transaction=0; transaction<(2*k)+1; transaction++){
            after[transaction] = 0;
        }
        for(int i=n-1; i>=0; i--){
            for(int transaction=1; transaction<=(2*k); transaction++){
                int profit = 0;
                if(transaction%2 == 0){
                    profit = max(-prices[i] + after[transaction-1],  after[transaction]);
                }
                else{
                    profit = max(prices[i] + after[transaction-1],  after[transaction]);
                }
                curr[transaction] = profit;
            }
            after = curr;
        }
        return after[2*k] ;
    }
};