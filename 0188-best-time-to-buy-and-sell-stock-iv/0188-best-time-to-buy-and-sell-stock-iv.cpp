class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> t(n+1, vector<int>((2*k)+1, 0));

        for(int i=0; i<n; i++){
            t[i][0] = 0;
        }
        for(int transaction=0; transaction<(2*k)+1; transaction++){
            t[n][transaction] = 0;
        }

        for(int i=n-1; i>=0; i--){
            for(int transaction=1; transaction<=(2*k); transaction++){
                int profit = 0;
                if(transaction%2 == 0){
                    profit = max(-prices[i] + t[i+1][transaction-1],  t[i+1][transaction]);
                }
                else{
                    profit = max(prices[i] + t[i+1][transaction-1],  t[i+1][transaction]);
                }
                t[i][transaction] = profit;
            }
        }
        return t[0][2*k] ;
    }
};