class Solution {
public:
    void dfs(int row, int col, int initialColor, int color, vector<vector<int>>& image){
        int m = image.size();
        int n = image[0].size();

        image[row][col] = color;

        if(row+1 < m && image[row+1][col] == initialColor){
            dfs(row+1, col, initialColor, color, image);
        }
        if(row-1 >= 0 && image[row-1][col] == initialColor){
            dfs(row-1, col, initialColor, color, image);
        }
        if(col+1 < n && image[row][col+1] == initialColor){
            dfs(row, col+1, initialColor, color, image);
        }
        if(col-1 >= 0 && image[row][col-1] == initialColor){
            dfs(row, col-1, initialColor, color, image);
        }
    
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        int initialColor = image[sr][sc];

        if(initialColor == color) return image;

        //vector<vector<int>> visited(m, vector<int>(n, 0));

        dfs(sr, sc, initialColor, color, image);

        return image;
    }
};