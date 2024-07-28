class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        int first = -1, second = -1;

        while(low <= high){
            int mid = low + ((high-low)/2);
            if(target == nums[mid]){
                first = mid;
                high = mid-1;
            }
            else if(target < nums[mid]){
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }

        int low2 = 0, high2 = n-1;
        while(low2 <= high2){
            int mid = low2 + ((high2 - low2)/2);
            if(target == nums[mid]){
                second = mid;
                low2 = mid + 1;
            }
            else if(target > nums[mid]){
                low2 = mid + 1;
            }
            else{
                high2 = mid-1;
            }
        }
        return {first, second};
    }
};