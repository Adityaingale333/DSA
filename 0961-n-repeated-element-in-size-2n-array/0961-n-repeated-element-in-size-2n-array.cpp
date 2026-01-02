class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();

        int len = n/2;

        vector<int> temp(1e4+1, 0);

        int ans = 0;
        for(int i=0; i<n; i++){
            temp[nums[i]]++;
            if(temp[nums[i]] == len){
                ans = nums[i];
            }
        }

        return ans;
    }
};