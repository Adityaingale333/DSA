class Solution {
public:
    void solve(vector<int>& nums){
        if(nums.size() == 1){
            return ;
        }

        vector<int> temp;
        for(int i=0; i<nums.size()-1; i++){
            temp.push_back((nums[i] + nums[i+1]) % 10);
        }

        nums = temp;
        solve(nums);
    }
    int triangularSum(vector<int>& nums) {
        solve(nums);

        return nums[0];
    }
};