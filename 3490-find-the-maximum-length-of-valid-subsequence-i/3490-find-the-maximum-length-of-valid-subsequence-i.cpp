class Solution {
public:
    int solve(int i, int state, vector<int>& nums, vector<vector<int>>& t){
        if(i == nums.size()){
            return 0;
        }
        
        if(t[i][state + 1] != -1){
            return t[i][state + 1];
        }

        int take = 0;
        if(state == -1){
            state = nums[i] % 2;
            take = 1 + solve(i+1, !state, nums, t);
        }
        else if(state == 0 && nums[i] % 2 == 0){
            take = 1 + solve(i+1, 1, nums, t);
        }
        else if(state == 1 && nums[i] % 2 == 1){
            take = 1 + solve(i+1, 0, nums, t);
        }

        int notTake = solve(i+1, state, nums, t);

        return t[i][state + 1] = max(take, notTake);
    }

    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        // state = -1, 0, 1
        // -1 -> kuch bhi utha le
        // 0 -> sirf even utha skta hai
        // 1 -> sirf odd utha skta hai

        vector<vector<int>> t(n, vector<int>(3, -1));

        int oddEven = solve(0, -1, nums, t);

        int even = 0;
        int odd = 0;

        for(int i=0; i<n; i++){
            if(nums[i] % 2 == 1){
                odd++;
            }
            else{
                even++;
            }
        }

        return max({oddEven, odd, even});
    }
};