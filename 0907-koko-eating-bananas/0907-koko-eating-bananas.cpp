class Solution {
public:
    double getHrs(vector<int> piles, int mid){
        int n = piles.size();
        double hrs = 0;
        for(int i=0; i<n; i++){
            hrs = hrs + ceil((double)piles[i]/(double)mid);
        }
        return hrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int largest = INT_MIN;

        for(int i=0; i<n; i++){
            largest = max(largest, piles[i]);
        }

        int ans = 0;
        int low = 1;
        int high = largest;

        while(low <= high){

            int mid = (low+high)/2;
            double hrs = getHrs(piles, mid);

            if(hrs <= h){
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