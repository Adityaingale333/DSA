class Solution {
public:
    void dfs(int u, unordered_map<int, vector<int>>& adj, vector<int>& visited, int& countNodes){
        visited[u] = 1;
        countNodes++;

        for(auto& v : adj[u]){
            if(!visited[v]){
                dfs(v, adj, visited, countNodes);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> adj;
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, 0);

        int components = 0;
        vector<int> sizeOfComponents;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                int countNodes = 0;
                dfs(i, adj, visited, countNodes);
                components++;
                sizeOfComponents.push_back(countNodes);
            }
        }

        long long ans = 0;
        for(int i=0; i<sizeOfComponents.size()-1; i++){
            ans = ans + ( (long long)sizeOfComponents[i] * (n - (long long)sizeOfComponents[i]) );
            n = n - sizeOfComponents[i];
        }

        return ans;
    }
};