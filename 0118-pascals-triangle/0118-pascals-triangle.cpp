class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;

        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            vector<int> temp(i+1, 1);
            int tempSize = temp.size();
            for(int j=1; j<tempSize-1; j++){
                temp[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans.push_back(temp);
        }

        return ans;
    }
};