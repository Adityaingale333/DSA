class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                int val = (int)sqrt((i*i) + (j*j) + 1.0);
                if((i != j) && val <= n && val * val == (i*i) + (j*j)){
                    ans++;
                }
            }
        }

        return ans;
    }
};