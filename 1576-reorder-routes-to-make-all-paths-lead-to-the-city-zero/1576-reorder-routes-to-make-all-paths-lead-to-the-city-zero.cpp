class Solution {
public:
    void dfs(int u, int parent, unordered_map<int, vector<pair<int, int>>>& adj, int& count){
        for(auto& it : adj[u]){
            int v = it.first;
            int dir = it.second;
            if(v == parent){
                continue;
            }
            if(dir == 1){
                count++;
            }
            dfs(v, u, adj, count);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto& edge : connections){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back({v, 1}); // given edge
            adj[v].push_back({u, 0}); // edge we made for traversal
        }

        int count = 0;

        dfs(0, -1, adj, count);

        return count;
    }
};