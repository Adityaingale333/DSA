class Solution {
public:
    int minSwaps(vector<int>& nums) {
       int n = nums.size();
       int totalOnes = 0;

       vector<int> temp(2*n);

       //Calculate total number of 1's in the array
       for(int i=0; i<2*n; i++){
        temp[i] = nums[i%n];
       } 

        //***Create a temporary array of size 2*n, to deal with circular array***
       for(int i=0; i<n; i++){
        if(nums[i]==1) totalOnes++;
       }

       int i=0, j=0;
       int currOnes = 0;
       int maxCount = 0;

       while(j < 2*n){
        if(temp[j] == 1){
            currOnes++;
        }

        if(j-i+1 > totalOnes){
            currOnes = currOnes - temp[i];
            i++;
        }

        maxCount = max(maxCount, currOnes);
        j++;
       } 
       return totalOnes - maxCount;
    }
};