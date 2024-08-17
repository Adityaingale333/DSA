class Solution {
public:
    int getDivas(vector<int> weights, int mid){
        int n = weights.size();
        int divas = 1;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum = sum + weights[i];
            if(sum > mid){
                divas++;
                sum = weights[i];
            }
        }
        return divas;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int largest = INT_MIN;
        int tsum = 0;
        for(int i=0; i<n; i++){
            largest = max(largest, weights[i]);
            tsum += weights[i]; 
        } 

        int ans = 0;
        int low = largest;
        int high = tsum;
        while(low <= high){
            int mid = (low+high)/2;
            int divas = getDivas(weights, mid);
            if(divas <= days){
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