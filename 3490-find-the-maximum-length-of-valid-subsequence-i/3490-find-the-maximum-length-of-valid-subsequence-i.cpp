class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        int oddEven = 0;
        bool firstOdd = false;
        int nextInOddEven = -1;
        for(int i=0; i<n; i++){
            if(nums[i]%2 == 1 && !firstOdd){
                firstOdd = true;
                oddEven++;
                nextInOddEven = 0;
            }
            else{
                if(nums[i]%2 == 1 && nextInOddEven == 1){
                    oddEven++;
                    nextInOddEven = 0;
                }
                else if(nums[i]%2 == 0 && nextInOddEven == 0){
                    oddEven++;
                    nextInOddEven = 1;
                }
            }
        }

        int evenOdd = 0;
        bool firstEven = false;
        int nextInEvenOdd = -1;
        for(int i=0; i<n; i++){
            if(nums[i]%2 == 0 && !firstEven){
                firstEven = true;
                evenOdd++;
                nextInEvenOdd = 1;
            }
            else{
                if(nums[i]%2 == 1 && nextInEvenOdd == 1){
                    evenOdd++;
                    nextInEvenOdd = 0;
                }
                else if(nums[i]%2 == 0 && nextInEvenOdd == 0){
                    evenOdd++;
                    nextInEvenOdd = 1;
                }
            }
        }

        int even = 0;
        int odd = 0;

        for(int i=0; i<n; i++){
            if(nums[i] % 2 == 1){
                odd++;
            }
            else{
                even++;
            }
        }

        return max({oddEven, evenOdd, even, odd});
    }
};