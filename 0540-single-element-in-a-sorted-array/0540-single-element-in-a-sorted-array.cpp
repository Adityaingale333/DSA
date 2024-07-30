class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;

        if(n == 1)return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        while(low <= high){
            int mid = low + ((high-low)/2);

            if(mid%2 == 0){
                if(nums[mid] == nums[mid+1]){
                    low = mid+1;
                }
                else if(nums[mid] == nums[mid-1]){
                    high = mid-1;
                }
                else{
                    return nums[mid];
                }
            }

            else{
                if(nums[mid] == nums[mid-1]){
                    low = mid+1;
                }
                else if(nums[mid] == nums[mid+1]){
                    high = mid-1;
                }
                else{
                    return nums[mid];
                }
            }
        }
        return -1;
    }
};