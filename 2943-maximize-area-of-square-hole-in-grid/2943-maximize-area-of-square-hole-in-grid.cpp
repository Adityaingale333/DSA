class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maxConsecutiveHBars = 1;
        int maxConsecutiveVBars = 1;

        int currConsecutiveHBars = 1;
        for(int i=1; i<hBars.size(); i++){
            if(hBars[i] - hBars[i-1] == 1){
                currConsecutiveHBars++;
            }
            else{
                currConsecutiveHBars = 1;
            }
            maxConsecutiveHBars = max(currConsecutiveHBars, maxConsecutiveHBars);
        }

        int currConsecutiveVBars = 1;
        for(int i=1; i<vBars.size(); i++){
            if(vBars[i] - vBars[i-1] == 1){
                currConsecutiveVBars++;
            }
            else{
                currConsecutiveVBars = 1;
            }
            maxConsecutiveVBars = max(currConsecutiveVBars, maxConsecutiveVBars);
        }

        int side = min(maxConsecutiveHBars, maxConsecutiveVBars) + 1;

        return side * side;
    }
};