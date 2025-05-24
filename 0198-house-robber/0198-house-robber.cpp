class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int prev2 = 0; // this is t[0] , 0 house me chori krne ke baad, obv 0 money mila hoga
        int prev = nums[0]; //this is t[1], 1st house me chori krne ke baad, uske pass kitne money hai

        for(int i=2; i<=n; i++){
            int pick = nums[i-1] + prev2;
            int skip = prev;
            int curri = max(pick, skip);

            prev2 = prev;
            prev = curri;
        } 
        return prev;
    }
};