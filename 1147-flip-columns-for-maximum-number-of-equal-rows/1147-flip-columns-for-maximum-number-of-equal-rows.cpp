class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        unordered_map<string, int> mp;

        for(auto& row:matrix){
            string rowKaNature = "";
            int firstVal = row[0];

            for(int col=0; col<n; col++){
                rowKaNature += (row[col] == firstVal) ? "s" : "c" ; 
            }
            mp[rowKaNature]++;                
        }

        int maxRow = 0;
        for(auto& it:mp){
            maxRow = max(maxRow, it.second);
        }
        return maxRow;
    }
};