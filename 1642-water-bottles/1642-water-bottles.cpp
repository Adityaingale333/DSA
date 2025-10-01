class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int empty = numBottles;

        while(empty >= numExchange){
            int extra = empty / numExchange;
            ans = ans + extra;
            int remaining = empty % numExchange;
            empty = extra + remaining; 
        }

        return ans;
    }
};