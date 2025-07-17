class Solution {
public:
    /*int solve(int i, int prev, int mod, int k, vector<int>& nums, vector<vector<int>>& t){
        if(i == nums.size()){
            return 0;
        }

        if(t[i][prev+1] != -1){
            return t[i][prev+1];
        }

        int take = 0;
        if(prev == -1 || (nums[i] + nums[prev]) % k == mod){
            take = 1 + solve(i+1, i, mod, k, nums, t);
        } 

        int notTake = solve(i+1, prev, mod, k, nums, t);

        return t[i][prev+1] = max(take, notTake);
    }*/
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        // row = 0 for mad value 0
        // row = 1 for mad value 1
        // row = 2 for mad value 2
        // row = 3 for mad value 3
        // ..... 
        // row = k-1 for mad value k-1
        vector<vector<int>> t(k, vector<int>(n, 1));

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                int mod = (nums[i] + nums[j]) % k ;

                // mod = 0 -> 0th row ka result
                // mod = 1 -> 1st row ka result
                // mod = k-1 -> k-1 wale orw ka result

                t[mod][i] = max(t[mod][i], t[mod][j] + 1);
                ans = max(ans, t[mod][i]);

            }
        }
        return ans;
    }
};