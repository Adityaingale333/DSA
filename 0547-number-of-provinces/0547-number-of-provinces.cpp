class Solution {
public:
    // we can get the total number of nodes from the size of the isConnected
    // then we can maintain a visited array on ehich we will iterate and visit every node
    // and the number of times traversal will be called will be the number of provinces
    // bcz traversal visited every interconnected nodes
    int n;
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited){
        visited[node] = true;

        for(int col=0; col<n; col++){
            if(!visited[col] && isConnected[node][col] == 1){
                dfs(col, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();

        // we can also use the given matrix

        /*unordered_map<int, vector<int>> adj;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }*/

        vector<bool> visited(n, false);

        int count = 0;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                count++;
                dfs(i, isConnected, visited);
            }
        }
        return count;
    }
};