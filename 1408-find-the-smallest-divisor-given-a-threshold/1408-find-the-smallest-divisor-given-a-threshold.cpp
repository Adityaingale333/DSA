class Solution {
public:
    double getSum(vector<int> nums, int mid){
        int n = nums.size();
        double sum = 0;
        for(int i=0; i<n; i++){
            sum = sum + ceil((double)nums[i]/(double)mid);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int largest = INT_MIN;
        for(int i=0; i<n; i++){
            largest = max(largest, nums[i]); 
        }

        int ans = 0;
        int low = 1;
        int high = largest;
        while(low <= high){
            int mid = (low+high)/2;
            double sum = getSum(nums, mid);
            if(sum <= threshold){
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