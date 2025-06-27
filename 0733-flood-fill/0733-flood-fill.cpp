class Solution {
public:
    void bfs(int i, int j, int initialColor, int color, vector<vector<int>>& image){
        int m = image.size();
        int n = image[0].size();

        image[i][j] = color;

        queue<pair<int,int>> q;
        q.push({i,j});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if(row+1 < m && image[row+1][col] == initialColor){
                q.push({row+1, col});
                image[row+1][col] = color;

            }

            if(row-1 >= 0 && image[row-1][col] == initialColor){
                q.push({row-1, col});
                image[row-1][col] = color;
            }

            if(col+1 < n && image[row][col+1] == initialColor){
                q.push({row, col+1});
                image[row][col+1] = color;
            }

            if(col-1 >= 0 && image[row][col-1] == initialColor){
                q.push({row, col-1});
                image[row][col-1] = color;
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        int initialColor = image[sr][sc];
        
        if(initialColor == color) return image;

        //vector<vector<int>> visited(m, vector<int>(n, 0));

        bfs(sr, sc, initialColor, color, image);

        return image;
    }
};