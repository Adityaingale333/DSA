class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {

        //In each iteration, set vec[i][j] to the minimum of rowSum[i] and colSum[j].
        //Subtract this value from both rowSum[i] and colSum[j].
        //Move to the next row if rowSum[i] becomes zero.
        //Move to the next column if colSum[j] becomes zero.

        int m = rowSum.size();
        int n = colSum.size();

        vector<vector<int>> vec(m, vector<int>(n,0));

        int i = 0; //row
        int j = 0; //col

        while(i < m && j < n){
            vec[i][j] = min(rowSum[i], colSum[j]);

            rowSum[i] = rowSum[i] - vec[i][j];
            colSum[j] = colSum[j] - vec[i][j];

            if(rowSum[i] == 0) i++;
            if(colSum[j] == 0) j++;
        }

        return vec;
    }
};