class Solution {
public:
    typedef pair<int, pair<int,int>> P;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        dist[0][0] = 0;

        priority_queue<P, vector<P>, greater<P>> minh;
        minh.push({0, {0,0}}); // diff, {row,col}

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while(!minh.empty()){
            int diff = minh.top().first;
            int row = minh.top().second.first;
            int col = minh.top().second.second;
            minh.pop();

            // if(row == m-1 && col == n-1) return diff; // we can early exit here we are using min heap, so we will get minimum diff at the up

            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow < m && nrow >= 0 && ncol < n && ncol >= 0){
                    int newEffort = max(abs(heights[row][col] - heights[nrow][ncol]), diff);

                    if(newEffort < dist[nrow][ncol]){
                        dist[nrow][ncol] = newEffort;
                        minh.push({ dist[nrow][ncol], {nrow, ncol} });
                    }
                }
            }
        }

        return dist[m-1][n-1];
    }
};