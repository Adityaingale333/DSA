class Solution {
public:
    bool possible(vector<int>& batteries, long long mid, int n){
        long long target = n * mid;

        for(int i=0; i<batteries.size(); i++){
            target = target - min(mid, (long long)batteries[i]);

            if(target <= 0){
                return true;
            }
        }

        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long smallest = LLONG_MAX;
        long long sum = 0;

        for(int i=0; i<batteries.size(); i++){
            smallest = min(smallest, (long long)batteries[i]);
            sum = sum + batteries[i];
        }

        long long l = smallest;
        long long r = sum/n;

        long long ans = 0;

        while(l <= r){
            long long mid = l + (r-l)/2;

            if(possible(batteries, mid, n)){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        return ans;
    }
};