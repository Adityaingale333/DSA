class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();

        int i=0; 
        int j=0;
        int w = 0;
        int ans = INT_MAX;
        while(j<n){
            if(blocks[j] == 'W'){
                w++;
            }

            if(j-i+1 == k){
                ans = min(ans,w);

                if(blocks[i] == 'W'){
                    w--;
                }
                i++;
            }

            j++;
        }
        return ans;
    }
};