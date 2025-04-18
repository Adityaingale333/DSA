class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> mulForward(n,0);
        vector<int> mulBackward(n,0);
        int mulf = 1;

        for(int i=0; i<n; i++){
            mulf = mulf * nums[i];
            mulForward[i] = mulf;
        }

        int mulb = 1;
        for(int i=n-1; i>=0; i--){
            mulb = mulb * nums[i];
            mulBackward[i] = mulb;
        }

        int j = 1;
        vector<int> ans(n,0);
        ans[0] = mulBackward[1];
        ans[n-1] = mulForward[n-2];
        while(j < n-1){
            int val = mulForward[j-1] * mulBackward[j+1];
            ans[j] = val;
            j++;
        }
        return ans;
    }
};