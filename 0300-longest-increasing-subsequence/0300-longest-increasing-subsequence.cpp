class Solution {
public:
    int solve(int i, int lastIdx, vector<int>& nums, vector<vector<int>>& t){
        if(i < 0){
            return 0;
        }
        
        if(t[i][lastIdx] != -1){
            return t[i][lastIdx];
        }

        int take = 0;
        if(lastIdx == nums.size() || nums[i] < nums[lastIdx]){
            take = 1 + solve(i-1, i, nums, t);
        }

        int notTake = solve(i-1, lastIdx, nums, t);

        return t[i][lastIdx] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> t(n, vector<int>(n+1, -1));
        return solve(n-1, n, nums, t);
    }
};