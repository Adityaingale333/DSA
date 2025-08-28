class Solution {
public:
    void sortDiagonal(int row, int col, vector<vector<int>>& grid, bool ascending){
        int i = row, j = col;

        vector<int> vec;
        while(i<grid.size() && j<grid.size()){
            vec.push_back(grid[i][j]);
            i++;
            j++;
        }

        if(ascending == true){
            sort(vec.begin(), vec.end());
        }
        else{
            sort(vec.begin(), vec.end(), greater<int>());
        }

        i=row, j=col;

        for(int& val : vec){
            grid[i][j] = val;
            i++;
            j++;
        }
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // bottom left
        for(int row=0; row<n; row++){
            sortDiagonal(row, 0, grid, false);
        }

        // top right
        for(int col=1; col<n; col++){
            sortDiagonal(0, col, grid, true);
        }

        return grid;
    }
};