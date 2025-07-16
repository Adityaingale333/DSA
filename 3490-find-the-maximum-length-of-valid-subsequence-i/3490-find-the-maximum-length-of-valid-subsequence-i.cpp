class Solution {
public:
    /*int solve(int i, int state, vector<int>& nums, vector<vector<int>>& t){
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
    }*/

    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        
        // for recursion
        // state = -1, 0, 1
        // -1 -> kuch bhi utha le
        // 0 -> sirf even utha skta hai
        // 1 -> sirf odd utha skta hai

        vector<vector<int>> t(n+1, vector<int>(3, 0));

        // for bottom up
        // state = 0, 1, 2
        // 0 -> kuch bhi utha le
        // 1 -> sirf even utha skta hai
        // 2 -> sirf odd utha skta hai
        for(int i=n-1; i>=0; i--){
            for(int state=0; state<3; state++){
                int take = 0;
                if(state == 0){
                    int nextState = (nums[i] % 2 == 0) ? 2 : 1;
                    take = 1 + t[i+1][nextState];
                }
                else if(state == 1 && nums[i] % 2 == 0){
                    take = 1 + t[i+1][2];
                }
                else if(state == 2 && nums[i] % 2 == 1){
                    take = 1 + t[i+1][1];
                }
                
                int notTake = t[i+1][state];

                t[i][state] = max(take, notTake);
            }
        }

        int oddEven = t[0][0];

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