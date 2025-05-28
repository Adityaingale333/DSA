class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        int s1 = sum/2;

        if(sum%2 != 0) return false;

        vector<vector<int>> t(n, vector<int>(s1+1, 0));

        for(int i=0; i<n; i++){
            t[i][0] = 1;
        }
        if(nums[0] <= s1) t[0][nums[0]] = 1;

        for(int i=1; i<n; i++){
            for(int j=1; j<s1+1; j++){
                bool notTake = t[i-1][j];
                bool take = false;
                if(nums[i] <= j){
                    take = t[i-1][j-nums[i]];
                }
                t[i][j] = take | notTake;
            }
        }

        return t[n-1][s1];
    }
};