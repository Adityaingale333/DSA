class Solution {
public:
    int reverseBits(int n) {
        vector<int> binary(32, 0);

        for(int i=31; i>=0; i--){
            binary[31-i] = (n >> i) & 1;
        }

        int ans = 0;
        for(int i=0; i<32; i++){
            if(binary[i] == 1){
                ans = ans + pow(2, i);
            }
        }

        return ans;
    }
};