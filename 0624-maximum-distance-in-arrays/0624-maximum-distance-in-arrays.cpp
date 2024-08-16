class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int MAX = arrays[0].back();
        int MIN = arrays[0].front();

        int result = 0;

        for(int i=1; i<arrays.size(); i++){
            int currMin = arrays[i].front();
            int currMax = arrays[i].back();

            result = max({result, abs(MAX - currMin), abs(MIN - currMax)});

            MAX = max(MAX, currMax);
            MIN = min(MIN, currMin);
        }

        return result;

    }
};