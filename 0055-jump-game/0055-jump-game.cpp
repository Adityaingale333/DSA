class Solution {
public:
    bool solve(int i, vector<int>& nums, vector<int>& t){
        if(i == nums.size()-1){
            return true;
        }

        if(t[i] != -1){
            return t[i];
        }

        int j = 1;
        while(j <= nums[i]){
            if(solve(i+j, nums, t)){
                return t[i] = true;
            }
            j++;
        }
        return t[i] = false;
    }
    bool canJump(vector<int>& nums) {
        vector<int> t(nums.size(), -1);
        return solve(0, nums, t);
    }
};