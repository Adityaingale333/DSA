class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int ans = INT_MAX;

        for(int i=0; i<=n-k; i++){
            int w = 0;
            for(int j=i; (j-i+1)<=k; j++){
                if(blocks[j] == 'W'){
                    w++;
                }
            }
            ans = min(ans,w);
        }
        return ans;
    }
};