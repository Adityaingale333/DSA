class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0;
        int r = 0;
        int count0 = 0;
        int len = 0, maxlen = 0;

        while(r<n){
            if(nums[r] == 0) count0++;

            if(count0 > k){
                if(nums[l] == 0) count0--;
                l++;
            }
            if(count0 <= k){
                len = r-l+1;
                maxlen = max(len,maxlen);
            }
            r++;
        }
        return maxlen;
    }
};