class Solution {
public:
    // int solve(int i, int rem, vector<int>& nums, vector<vector<int>>& t){
    //     if(i >= nums.size()){
    //         if(rem == 0) return 0;
    //         return INT_MIN;
    //     }
        
    //     if(t[i][rem] != -1){
    //         return t[i][rem];
    //     }

    //     int take = nums[i] + solve(i+1, (rem+nums[i]) % 3, nums, t);
    //     int notTake = solve(i+1, rem, nums, t);

    //     return max(take, notTake);
    // }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> t(n+1, vector<int>(3, 0));

        t[n][0] = 0;
        t[n][1] = INT_MIN;
        t[n][2] = INT_MIN;

        for(int i=n-1; i>=0; i--){
            for(int rem=0; rem<3; rem++){
                int take = nums[i] + t[i+1][(rem+nums[i]) % 3];
                int notTake = t[i+1][rem];

                t[i][rem] = max(take, notTake);
            }
        }

        return t[0][0];
    }
};