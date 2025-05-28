class Solution {
public:
    bool solve(int i, int s1, vector<int>& nums, vector<vector<int>>& t){
        if(s1 == 0){
            return true;
        }
        if(i == 0) return nums[0] == s1 ? 1 : 0;

        if(t[i][s1] != -1){
            return t[i][s1];
        }

        bool notTake = solve(i-1, s1, nums, t);

        bool take = false;
        if(nums[i] <= s1){
            take = solve(i-1, s1-nums[i], nums, t);
        }
        
        return t[i][s1] = take | notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        int s1 = sum/2;

        if(sum%2 != 0) return false;

        vector<vector<int>> t(n, vector<int>(s1+1, -1));

        return solve(n-1, s1, nums, t);
    }
};