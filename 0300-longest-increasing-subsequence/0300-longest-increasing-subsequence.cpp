class Solution {
public:
    int solve(int i, int prevIdx, vector<int>& nums, vector<vector<int>>& t){
        if(i == nums.size()){
            return 0;
        }

        if(t[i][prevIdx+1] != -1){
            return t[i][prevIdx+1];
        }

        int len = solve(i+1, prevIdx, nums, t);

        if(prevIdx == -1 || nums[i] > nums[prevIdx]){
            len = max(len, 1 + solve(i+1, i, nums, t));
        }
        return t[i][prevIdx+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> t(n, vector<int>(n+1, -1));
        return solve(0, -1, nums, t);  
    }
};