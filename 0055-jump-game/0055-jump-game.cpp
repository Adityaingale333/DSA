class Solution {
public:
    /*bool solve(int i, vector<int>& nums, vector<int>& t){
        if(i == nums.size()-1){
            return true;
        }

        if(t[i] != -1){
            return t[i];
        }

        int j = 1;
        while(j <= nums[i]){
            if(solve(i+j, nums, t)){
                return t[i] = true;
            }
            j++;
        }
        return t[i] = false;
    }*/
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        //vector<int> t(nums.size(), -1);

        vector<bool> t(n, false);

        t[n-1] = true;

        for(int i=n-2; i>=0; i--){
            for(int j=1; j<=nums[i]; j++){
                if(t[i+j]){
                    t[i] = true;
                    break;
                }
            }
        }
        return t[0];
    }
};