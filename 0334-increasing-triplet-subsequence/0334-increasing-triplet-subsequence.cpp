class Solution {
public:
    /*int solve(int i, int prev, vector<int>& nums, vector<vector<int>>& t){
        if(i == nums.size()){
            return 0;
        }

        if(t[i][prev+1] != -1){
            return t[i][prev+1];
        }

        int take = 0;
        if(prev == -1 || nums[i] > nums[prev]){
            take = 1 + solve(i+1, i, nums, t);
        }

        int notTake = solve(i+1, prev, nums, t);

        return t[i][prev+1] = max(take, notTake);
    }*/
    bool increasingTriplet(vector<int>& nums) {
        /*int n = nums.size();

        vector<int> t(n, 1);

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    t[i] = max(t[i], t[j]+1);
                }
            }
            if(t[i] > 2) return true;
        }

        return false;*/

        int n = nums.size();

        int num1 = INT_MAX;
        int num2 = INT_MAX;

        for(int i=0; i<n; i++){
            if(nums[i] <= num1){
                num1 = nums[i];
            }
            else if(nums[i] <= num2){
                num2 = nums[i];
            }
            else{
                return true;
            }
        }

        return false;
    }
};