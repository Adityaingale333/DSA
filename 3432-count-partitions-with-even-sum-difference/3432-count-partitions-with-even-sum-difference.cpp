class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n, 0);
        prefix[0] = nums[0];

        for(int i=1; i<n; i++){
            prefix[i] = nums[i] + prefix[i-1];
        }

        int ans = 0;
        for(int i=0; i<n-1; i++){
            if(abs(prefix[i] - (prefix[n-1] - prefix[i])) % 2 == 0){
                ans++;
            }
        }
        return ans;
    }
};