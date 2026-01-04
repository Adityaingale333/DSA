class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;

        for(int i=0; i<n; i++){
            int divCount = 0;
            int sum = 0;
            for(int j=1; j*j <= nums[i]; j++){
                if(nums[i] % j == 0){

                    divCount = nums[i]/j == j ? divCount + 1 : divCount + 2;
                    sum = nums[i]/j == j ? sum + j : sum + nums[i]/j + j;
                }

                if(divCount > 4){
                    break;
                }
            }
            if(divCount == 4){
                ans = ans + sum;
            }
        }

        return ans;
    }
};