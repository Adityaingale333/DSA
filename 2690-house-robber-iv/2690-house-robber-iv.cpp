class Solution {
public:
    bool isPossible(vector<int>& nums, int mid, int k){
        int house = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] <= mid){
                house++;
                i++;
            }
        }
        return house >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();

        int low = INT_MAX;
        int high = INT_MIN;
        for(int i=0; i<n; i++){
            low = min(low, nums[i]);
            high = max(high, nums[i]);
        }

        int ans = high;
        while(low <= high){
            int mid = (low + high) / 2;

            if(isPossible(nums, mid, k)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};