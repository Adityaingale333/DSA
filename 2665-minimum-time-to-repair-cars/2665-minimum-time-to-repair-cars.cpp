class Solution {
public:
    bool isPossible(vector<int>& ranks, long long mid, int cars){
        long long repaired = 0;
        for(int i=0; i<ranks.size(); i++){
            repaired += sqrt(mid/ranks[i]) ;
        }
        return repaired >= cars;
    } 
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();

        int maxRank = INT_MIN;
       for(int i=0; i<n; i++){
            maxRank = max(maxRank, ranks[i]);
       } 

       long long low = 1;
       long long high = 1LL * maxRank * cars * cars; // binary search on time

       long long ans = -1;

       while( low <= high){
            long long mid = low + (high - low)/2;

            if(isPossible(ranks, mid, cars)){
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