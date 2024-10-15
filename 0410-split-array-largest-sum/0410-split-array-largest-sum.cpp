class Solution {
public:
    int splitGivenSum(vector<int> nums, int mid){
        int count = 1;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum = sum + nums[i];
            if(sum > mid){
                count++;
                sum = nums[i];
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        if(n<k) return -1;

        int largest = INT_MIN;
        int tsum = 0;
        for(int i=0; i<n; i++){
            largest = max(largest, nums[i]);
            tsum = tsum + nums[i];
        }

        int low = largest, high = tsum;
        int ans = 0;
        while(low <= high){
            int mid = (low+high)/2;
            int split = splitGivenSum(nums, mid);
            if(split <= k){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};