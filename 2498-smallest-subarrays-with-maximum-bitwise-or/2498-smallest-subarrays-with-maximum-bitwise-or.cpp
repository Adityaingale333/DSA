class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> setBitIdx(32, -1); // in this we will store the min idxthrough which we can set the ith bit

        vector<int> ans(n);

        for(int i=n-1; i>=0; i--){
            int maxIdx = i;
            for(int j=0; j<32; j++){
                if(!(nums[i] & (1 << j))){ // if jth bit is not set
                    if(setBitIdx[j] != -1){
                        maxIdx = max(maxIdx, setBitIdx[j]);
                    }
                }
                else{
                    setBitIdx[j] = i;
                }
            }

            ans[i] = maxIdx - i + 1;
        }

        return ans;
    }
};