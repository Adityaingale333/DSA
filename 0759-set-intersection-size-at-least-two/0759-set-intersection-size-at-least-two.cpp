class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), [](
            vector<int> a, vector<int> b){
                if(a[1] == b[1]){
                    return a[0] > b[0];
                }
                return a[1] < b[1];
            }
        );

        vector<int> maxi(2, 0);
        maxi[0] = intervals[0][1] - 1;
        maxi[1] = intervals[0][1];

        int count = 2;

        for(int i=1; i<n; i++){
            if(maxi[1] < intervals[i][0]){
                count = count + 2;
                maxi[0] = intervals[i][1] - 1;
                maxi[1] = intervals[i][1];
            }
            else if(maxi[0] < intervals[i][0]){
                count = count + 1;
                maxi[0] = maxi[1];
                maxi[1] = intervals[i][1];
            }
        }

        return count;
    }
};