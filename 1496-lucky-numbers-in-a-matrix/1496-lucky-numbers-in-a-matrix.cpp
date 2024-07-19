class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector <int> rowMin(m);
        vector <int> colMax(n);
        vector <int> ans;

        for(int row=0; row<m; row++){
            int minEl = INT_MAX;
            for(int col=0; col<n; col++){
                minEl = min(minEl, matrix[row][col]);
            }
            rowMin[row] = minEl;
        }

        for(int col=0; col<n; col++){
            int maxEl = INT_MIN;
            for(int row=0; row<m; row++){
                maxEl = max(maxEl, matrix[row][col]);
            }
            colMax[col] = maxEl;
        }

        for(int row=0; row<m; row++){
            for(int col=0; col<n; col++){
                if(matrix[row][col]==rowMin[row] && matrix[row][col]==colMax[col]){
                    ans.push_back(rowMin[row]);
                }
            }
        }

        return ans;
    }
};