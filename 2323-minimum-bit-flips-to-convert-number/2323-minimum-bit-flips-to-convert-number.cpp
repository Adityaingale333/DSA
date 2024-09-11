class Solution {
public:
    int minBitFlips(int start, int goal) {
        int XOR = start ^ goal ;
        int count = 0;

        while(XOR){
            XOR = XOR & XOR-1;
            count++;
        }
        return count;
    }
};