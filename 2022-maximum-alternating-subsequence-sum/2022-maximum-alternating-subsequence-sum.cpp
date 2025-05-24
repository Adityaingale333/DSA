class Solution {
public:
    long long t[100001][2];
    long long solve(int idx, bool flag, vector<int>& nums){
        if(idx >= nums.size()){
            return 0;
        }

        if(t[idx][flag] != -1){
            return t[idx][flag];
        }

        long long skip = solve(idx+1, flag, nums);

        long long val = nums[idx];
        if(flag == false){
            val = -val;
        }

        long long take = val + solve(idx+1, !flag, nums);

        return t[idx][flag] = max(skip, take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int idx = 0;
        bool flag = true;

        memset(t, -1, sizeof(t));

        return solve(idx, flag, nums); // idx = 0 means even index, so flag -> true '+'
    }
};