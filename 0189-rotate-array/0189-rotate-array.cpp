class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int newk = k%n; // to wrap around
       int low1 = 0, high1 = n-newk-1;

       while(low1 <= high1){
        swap(nums[low1], nums[high1]);
        low1++;
        high1--;
       } 


       int low2 = n-newk, high2 = n-1; 

       while(low2 <= high2){
        swap(nums[low2], nums[high2]);
        low2++;
        high2--;
       }

       int low3 = 0, high3 = n-1;

       while(low3 <= high3){
        swap(nums[low3], nums[high3]);
        low3++;
        high3--;
       }

    }
};