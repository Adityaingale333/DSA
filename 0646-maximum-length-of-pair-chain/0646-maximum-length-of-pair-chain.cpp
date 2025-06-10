class Solution {
public:
   
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> t(n+1, vector<int>(n+1, 0));

        for(int i=n-1; i>=0; i--){
            for(int lastIdx=i-1; lastIdx>=-1; lastIdx--){
                int notTake = t[i+1][lastIdx+1];
                int take = 0;
                if(lastIdx == -1 || pairs[i][0] > pairs[lastIdx][1]){
                    take = 1 + t[i+1][i+1];
                }
                t[i][lastIdx+1] = max(take, notTake);
            }
        }
        return t[0][-1+1] ;
    }
};