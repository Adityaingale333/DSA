class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();

        int i=0;

        long long ans = 0;

        while(i < n){
            int j = i;

            while(j < n-1 && prices[j] - prices[j+1] == 1){
                j++;
            }
            
            long long len = j-i+1;
            ans = ans + (((len)*(len+1)) / 2);

            i = j+1;
        }

        return ans;
    }
};