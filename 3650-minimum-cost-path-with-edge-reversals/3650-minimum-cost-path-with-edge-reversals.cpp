class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for(auto& it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, 2*wt});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh; // dist, node

        vector<int> ans(n, INT_MAX);
        ans[0] = 0;

        minh.push({0, 0});

        while(!minh.empty()){
            int d = minh.top().first;
            int node = minh.top().second;
            minh.pop();

            if(node == n-1){
                return ans[n-1];
            }

            for(auto& it : adj[node]){
                int adjNode = it.first;
                int dist = it.second;

                if(d + dist < ans[adjNode]){
                    ans[adjNode] = d + dist;
                    minh.push({d + dist, adjNode});
                }
            }
        }
        return -1;
    }
};