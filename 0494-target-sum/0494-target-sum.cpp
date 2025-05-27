class Solution {
public: 
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }

        // s1 - s2 = target -> s1 + s2 = sum
        // s1 - (sum - s1) = target -> s1 = (target + sum)/2
        int s1 = (target + sum)/2;

        if(sum < abs(target) || (target+sum)%2 != 0) return 0;

        vector<vector<int>> t(n+1, vector<int>(s1+1, 0));

        t[0][0] = 1;

        for(int i=1; i<n+1; i++){
            for(int j=0; j<s1+1; j++){
                if(nums[i-1] <= j){
                    t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][s1];
    }
};