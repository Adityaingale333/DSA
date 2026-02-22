class Solution {
public:
    int binaryGap(int n) {
        int temp = n;

        vector<int> binary;

        while(temp){
            binary.push_back(temp % 2);
            temp = temp / 2;
        }

        int prev = -1;
        int ans = 0;

        for(int i=0; i<binary.size(); i++){
            if(binary[i] == 1){
                if(prev != -1) ans = max(ans, i - prev);
                prev = i;
            }
        }

        return ans;
    }
};