class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<uint64_t>> t(n, vector<uint64_t>(amount+1, 0));

        for(int i=0; i<n; i++){
            t[i][0] = 1;
        }

        for(int i=0; i<=amount; i++){
            if(i % coins[0] == 0){
                t[0][i] = 1;
            }
            else{
                t[0][i] = 0;
            }
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<amount+1; j++){
                uint64_t notTake = t[i-1][j];
                uint64_t take = 0;
                if(coins[i] <= j){
                    take = t[i][j-coins[i]];
                }
                t[i][j] = take + notTake;
            }
        }
        return t[n-1][amount]; 
    }
};