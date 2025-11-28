class Solution {
public:
int dfs(int curr, int parent, unordered_map<int, vector<int>>& adj, vector<int>& values, int k, int& count){
    int sum = values[curr];

    for(int& it : adj[curr]){
        if(it != parent){
            sum = sum + dfs(it, curr, adj, values, k, count);
            sum = sum % k;
        }
    }

    sum = sum % k;
    if(sum == 0){
        count++;
    }
    return sum;
}
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int, vector<int>> adj;
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int count = 0;

        dfs(0, -1, adj, values, k, count);
        
        return count;
    }
};