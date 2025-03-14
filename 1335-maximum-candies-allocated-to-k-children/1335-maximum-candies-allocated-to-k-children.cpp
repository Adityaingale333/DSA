class Solution {
public:
    bool canDistr(vector<int>& candies, int mid, long long k){
        long long count = 0;
        for(int i=0; i<candies.size(); i++){
            count = count + candies[i]/mid;
            if(count >= k){
                return true;
            }
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();

        int low = 1;
        int high = INT_MIN;
        long long total = 0;

        for(int i=0; i<n; i++){
            high = max(high, candies[i]);
            total = total + candies[i];
        }

        if(total < k) return 0;

        int ans = 0;
        while(low <= high){
            int mid = (low + high) / 2;

            if(canDistr(candies, mid, k)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};