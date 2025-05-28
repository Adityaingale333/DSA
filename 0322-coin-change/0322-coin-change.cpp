class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        for(int T=0; T<=amount; T++){
            if(T % coins[0] == 0){
                dp[0][T] = T/coins[0];
            }
            else{
                dp[0][T] = 1e9; 
            }
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<amount+1; j++){
                int notTake = dp[i-1][j];
                int take = INT_MAX;
                if(coins[i] <= j){
                    take = 1 + dp[i][j-coins[i]];
                }
                dp[i][j] = min(take, notTake);
            }
        }

        int ans = dp[n-1][amount];
        if(ans >= 1e9) return -1;
        return ans;
    }
};