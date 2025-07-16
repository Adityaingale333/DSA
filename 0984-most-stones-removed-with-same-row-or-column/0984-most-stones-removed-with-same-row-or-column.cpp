class Solution {
public:
    void dfs(int index, vector<bool>& visited, vector<vector<int>>& stones){
        visited[index] = 1;

        for(int i=0; i<stones.size(); i++){
            int row = stones[index][0];
            int col = stones[index][1];

            if(visited[i] == false && ( stones[i][0] == row || stones[i][1] == col )){
                dfs(i, visited, stones);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        vector<bool> visited(n, false);

        int components = 0;
        for(int i=0; i<n; i++){
            if(visited[i] == false){
                dfs(i, visited, stones);
                components++;
            }
        }

        return n - components;
    }
};