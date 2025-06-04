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

        /*vector<vector<int>> t(n+2, vector<int>(2, 0));

        for(int buy=0; buy<2; buy++){
            t[n+1][buy] = t[n][buy] = 0;
        }*/

        // space optimization, using vector
        vector<int> after2(2, 0);
        vector<int> after1(2, 0); // we need two vector bcz we are dealing with n+2
        vector<int> curr(2, 0);

        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<2; buy++){
                int profit = 0;
                if(buy){
                    profit = max( -prices[i] + after1[0], after1[1] );
                }
                else{
                    profit = max( prices[i] + after2[1], after1[0] );
                }
                curr[buy] = profit;
            }
            after2 = after1;
            after1 = curr;
        }
        return after1[1];
    }
};