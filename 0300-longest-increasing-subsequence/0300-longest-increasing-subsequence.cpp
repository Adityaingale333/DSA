class Solution {
public:
    /*int solve(int i, int prevIdx, vector<int>& nums, vector<vector<int>>& t){
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
    }*/
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> after(n+1, 0);
        vector<int> curr(n+1, 0);

        for(int i=n-1; i>=0; i--){
            for(int prevIdx = i-1; prevIdx>=-1; prevIdx--){
                int len = after[prevIdx+1];
                if(prevIdx == -1 || nums[i] > nums[prevIdx]){
                    len = max(len, 1 + after[i+1]);
                }
                curr[prevIdx+1] = len;
            }
            after = curr;
        }
        return after[-1+1];  
    }
};