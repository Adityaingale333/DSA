class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int count1 = 0;
        int g = 0;
        for(int it : nums){
            if(it == 1){
                count1++;
            }
            g = gcd(g, it);
        }

        if(count1 > 0){
            return n - count1;
        }

        if(g > 1){
            return -1;
        }

        int ans = INT_MAX;
        for(int i=0; i<n-1; i++){
            int currGCD = 0;
            for(int j=i; j<n; j++){
                currGCD = gcd(currGCD, nums[j]);
                if(currGCD == 1){
                    ans = min(ans, j-i+1);
                    break;
                }
            }
        }

        return ans + n -2; 
    }
};