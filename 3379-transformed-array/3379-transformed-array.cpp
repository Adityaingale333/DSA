class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                ans.push_back(nums[i]);
            }
            else if(nums[i] > 0){
                ans.push_back(nums[(i+nums[i])%n]);
            }
            else{
                int idx = i - abs(nums[i]);
                idx = (idx % n + n) % n;
                ans.push_back(nums[idx]);
            }
        }

        return ans;
    }
};