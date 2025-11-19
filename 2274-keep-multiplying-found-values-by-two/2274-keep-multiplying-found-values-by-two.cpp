class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();

        bool flag = true;
        while(flag){
            for(int i=0; i<n; i++){
                if(nums[i] == original){
                    original = original * 2;
                    flag = false;
                    break;
                }
            }
            flag = !flag;
        }

        return original;
    }
};