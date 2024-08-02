class Solution {
public:
    int minSwaps(vector<int>& nums) {
       int n = nums.size();
       int totalOnes = 0;

        //Calculate total number of ones
       for(int i=0; i<n; i++){
        if(nums[i]==1) totalOnes++;
       }

       int i=0, j=0;
       int currOnes = 0;
       int maxCount = 0;

       while(j < 2*n){
        if(nums[j%n] == 1){   // mod n, to wrap around the array. (Circular array)
            currOnes++;
        }

        if(j-i+1 > totalOnes){
            currOnes = currOnes - nums[i%n];  // mod n, to wrap around the array. (Circular array)
            i++;
        }

        maxCount = max(maxCount, currOnes);
        j++;
       } 
       return totalOnes - maxCount;
    }
};