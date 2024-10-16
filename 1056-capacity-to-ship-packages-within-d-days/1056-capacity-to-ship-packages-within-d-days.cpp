class Solution {
public:
    int DaysGivenCapacity(vector<int> weights, int mid){
        int count = 1;
        int sum = 0;
        for(int i=0; i<weights.size(); i++){
            sum = sum + weights[i];
            if(sum > mid){
                count++;
                sum = weights[i];
            }
        }
        return count;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int largest = INT_MIN;
        int tsum = 0;
        for(int i=0; i<weights.size(); i++){
            largest = max(largest, weights[i]);
            tsum = tsum + weights[i];
        }
        int low = largest, high = tsum;
        int ans = 0;
        while(low <= high){
            int mid = (low+high)/2;
            int Day = DaysGivenCapacity(weights, mid);
            if(Day <= days){
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