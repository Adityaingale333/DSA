class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size();

        int north = 0;
        int south = 0;
        int east = 0;
        int west = 0;

        int maxMD = 0;

        for(int i=0; i<n; i++){
            if(s[i] == 'N') north++;
            else if(s[i] == 'S') south++;
            else if(s[i] == 'W') west++;
            else if(s[i] == 'E') east++;

            int currMD = abs(north-south) + abs(west-east);

            int steps = i+1;
            int wasted = steps - currMD; // if this is 0 then it means it is bezt case scenario

            int canCover = 0;
            if(wasted != 0){
                canCover = min(2*k, wasted);
            }

            int finalCurrMD = currMD + canCover;

            maxMD = max(maxMD, finalCurrMD);
        }

        return maxMD;
    }
};