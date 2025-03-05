class Solution {
public:
    long long coloredCells(int n) {
        long long cells = 1;
        long long time = 1;

        while(time <= n){
            cells = cells + 4*(time-1);
            time++;
        }

        return cells;
    }
};