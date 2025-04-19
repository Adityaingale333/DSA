class Solution {
public:
    int maxProduct(vector<int>& nums) {
// if we have all positive then ans is whole array
// if we have even negative no. then also ans is whole array
// but if we have odd negative no. then we need to find product before and after of that number
// ex -> [2 3 -2 4] 2*3 and 4
// take care of 0, reset the values to 1
        int n = nums.size();
        int maxProduct = INT_MIN;
        int prefix = 1;
        int suffix = 1;
        int ans = nums[0];
        for(int i=0; i<n; i++){
            if(prefix ==  0) prefix = 1;
            if(suffix == 0) suffix = 1;

            prefix = prefix * nums[i];
            suffix = suffix * nums[n-i-1];

            ans = max(ans, max(prefix, suffix));
        }
        return ans;
    }
};