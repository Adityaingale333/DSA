class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int sum = (n*(n+1)) / 2;
        int arrSum = 0;

        for(int i=0; i<n; i++){
            arrSum = arrSum + nums[i];
        }

        int ans = sum - arrSum;

        return ans;
    }
};