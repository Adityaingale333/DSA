class Solution {
public:
    // we can get the total number of nodes from the size of the isConnected
    // then we can maintain a visited array on ehich we will iterate and visit every node
    // and the number of times traversal will be called will be the number of provinces
    // bcz traversal visited every interconnected nodes
    void dfs(int node,  unordered_map<int, vector<int>>& adj, vector<bool>& visited){
        visited[node] = true;

        for(auto& it : adj[node]){
            if(!visited[it]){
                dfs(it, adj, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        unordered_map<int, vector<int>> adj;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);

        int count = 0;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                count++;
                dfs(i, adj, visited);
            }
        }
        return count;
    }
};