class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int empty = numBottles;

        while(empty >= numExchange){
            ans++;
            empty = empty - numExchange;
            empty++;
            numExchange++;
        }

        return ans;
    }
};