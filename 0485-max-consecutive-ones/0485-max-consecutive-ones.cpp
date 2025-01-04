class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int i=0, j=0;
        int maxlen = 0;
        int currlen = 0;

        while(j<n){
            if(nums[j] != 1){
                currlen = 0;
                j++;
                i = j;
            }
            else{
                currlen = j-i+1;
                maxlen = max(maxlen, currlen);
                j++;
            }
        }
        return maxlen;
    }
};