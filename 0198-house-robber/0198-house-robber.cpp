class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n+1, 0); // t[i] -> max stolen money till house i
        t[0] = 0; // 0 house me chori krne ke baad, obv 0 money mila hoga
        t[1] = nums[0]; // 1st house me chori krne ke baad, uske pass kitne money hai

        for(int i=2; i<=n; i++){
            int pick = nums[i-1] + t[i-2];
            int skip = t[i-1];
            t[i] = max(pick, skip);
        } 
        return t[n];
    }
};