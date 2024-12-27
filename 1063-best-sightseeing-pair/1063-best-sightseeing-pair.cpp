class Solution {
public:
// rearrange the question like, (values[i]+i) + (values[j]-j)
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int max_Till_Now = values[0]+0;
        int result = 0;

        for(int j=1; j<n; j++){
            int x = values[j]-j;
            int y = max_Till_Now;
            result = max(result, x+y);
            max_Till_Now = max(max_Till_Now, values[j]+j); // actually its values[i]+i, but here pointer is j 
        }
        return result;
    }
};