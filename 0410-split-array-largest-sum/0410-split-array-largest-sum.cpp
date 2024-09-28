class Solution {
public:

    int splitGivenSum(vector<int>& arr, int mid){
        int n = arr.size();
        int sum = 0, count = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum > mid){
                count++;
                sum = arr[i];
            }
        }
        if(sum!=0) count++;
        return count;
    }

    int splitArray(vector<int>& nums, int k) {
     int n = nums.size();
     int largest = INT_MIN, tsum = 0;
     for(int i=0;i<n; i++){
        largest = max(largest, nums[i]);
        tsum = tsum + nums[i];
     }

    if(n<k) return -1;

     int low = largest, high = tsum;
     while(low<=high){
        int mid = (low+high)/2;
        int split = splitGivenSum(nums, mid);
        if(split <= k){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
     }
     return low;   
    }
};