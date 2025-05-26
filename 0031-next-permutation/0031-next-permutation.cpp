class Solution {
public:
// we start looking from right to left(<-- <-- <--) for the first element which is smaller than its
// next element (3 4) (5 8 7), here they are (3) (5) {nums[i-1] < nums[i]}
// now we will take that element and look for the next greater element from right side (<-- <-- <--)
// (5 8 7) here it will be (7)
// now swap both (5) and (7) 
// reverse everything right from the position of nums[i-1]
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int idx = -1; 
        for(int i=n-1; i>0; i--){
            if(nums[i-1] < nums[i]){
                idx = i-1;
                break;
            }
        }

        if(idx == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int j=n-1; j>idx; j--){
            if(nums[j] > nums[idx]){
                swap(nums[idx], nums[j]);
                break;
            }
        }

        reverse(nums.begin()+idx+1, nums.end());

    }
};