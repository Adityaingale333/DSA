class Solution {
public:
    // Define a ways array which would contain the number of possible shortest ways/paths for each node. 
    // Eventually, we would want to return ways[n-1] where n= Number of nodes.
    int M = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<long long, vector<pair<long long,long long>>> adj;
        for(auto& edge : roads){
            long long u = edge[0];
            long long v = edge[1];
            long long wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> minh;
        minh.push({0, 0}); // dist, node

        vector<long long> dist(n, 1e18);
        dist[0] = 0;

        vector<long long> ways(n, 0);
        ways[0] = 1;

        while(!minh.empty()){
            long long u = minh.top().second;
            long long d = minh.top().first;
            minh.pop();

            for(auto& it : adj[u]){
                long long v = it.first;
                long long wt = it.second;

                // this is the first time we are arriving, with this short distance
                if(d + wt < dist[v]){
                    dist[v] = d + wt;
                    minh.push({dist[v], v});
                    ways[v] = ways[u] % M; // this is the first time. so whatever ways we reached u, it will be same 
                }
                else if(d + wt == dist[v]){
                    ways[v] = ( ways[v] + ways[u] ) % M;
                }
            }
        }
        return (int)ways[n-1] % M;
    }
};