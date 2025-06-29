class Solution {
public:
    int M = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0, r=n-1;

        sort(nums.begin(), nums.end());

        vector<int> power(n);
        power[0] = 1;

        for(int i=1; i<n; i++){
            power[i] = (power[i-1] * 2) % M;
        }

        int ans = 0;
        while(l <= r){
            if(nums[l] + nums[r] <= target){
                ans = ans % M + power[r-l] % M;
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
    }
};