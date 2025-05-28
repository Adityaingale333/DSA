class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }

        int s1 = (sum + target)/2;

        if(abs(target) > sum || (target+sum)%2 != 0) return 0;

        vector<vector<int>> t(n, vector<int>(s1+1, 0));


        if(nums[0] == 0){
            t[0][0] = 2;
        }
        else{
            t[0][0] = 1;
        }

        if(nums[0]!=0 && nums[0]<=s1) t[0][nums[0]] = 1;

        for(int i=1; i<n; i++){
            for(int j=0; j<s1+1; j++){
                int notTake = t[i-1][j];
                int take = 0;
                if(nums[i] <= j){
                    take = t[i-1][j-nums[i]];
                } 
                t[i][j] = take + notTake;
            }
        }

        return t[n-1][s1];
    }
};