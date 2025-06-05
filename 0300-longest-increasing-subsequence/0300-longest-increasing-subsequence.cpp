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

        vector<vector<int>> t(n+1, vector<int>(n+1, 0));

        for(int i=n-1; i>=0; i--){
            for(int prevIdx = i-1; prevIdx>=-1; prevIdx--){
                int len = t[i+1][prevIdx+1];
                if(prevIdx == -1 || nums[i] > nums[prevIdx]){
                    len = max(len, 1 + t[i+1][i+1]);
                }
                t[i][prevIdx+1] = len;
            }
        }
        return t[0][-1+1];  
    }
};