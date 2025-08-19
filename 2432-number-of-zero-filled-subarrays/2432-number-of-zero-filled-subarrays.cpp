class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();

        int j=0;
        long long ans = 0;
        int count0 = 0;

        while(j < n){
            if(nums[j] == 0){
                count0++;
            }
            else{
                count0 = 0;
            }

            if(count0 != 0){
                ans = ans + count0;
            }  
            j++;  
        }

        return ans;
    }
};