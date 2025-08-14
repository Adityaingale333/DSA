class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int totalSum = 0;
        for(int i=0; i<n; i++){
            totalSum += nums[i];
        }

        int findSum = totalSum - x;

        int i=0, j=0;
        int maxLen = -1;
        int currSum = 0;

        while(j < n){
            currSum = currSum + nums[j];

            while(currSum > findSum && i<=j){
                currSum = currSum - nums[i];
                i++;
            }

            if(currSum == findSum){
                maxLen = max(maxLen, j-i+1);
            }

            j++;
        } 

        return maxLen == -1 ? -1 : n - maxLen;
    }
};