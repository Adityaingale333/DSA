class Solution {
public:
    int M = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        vector<int> prefix(n, 0);
        prefix[0] = arr[0];

        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + arr[i];
        }

        int odd = 0;
        int even = 1; // before the start of array sum is 0, which is even
        int ans = 0;

        for(int i=0; i<n; i++){
            if(prefix[i] % 2 == 0){
                ans = (ans + odd) % M;
                even++;
            }
            else{
                ans = (ans + even) % M;
                odd++;
            }
        }

        return ans;
    }
};