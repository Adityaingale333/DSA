class Solution {
public:
    // DIJKSTRA ALGORITHM
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> adj;
        for(auto& edge : times){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
        }

        vector<int> dist(n+1, 1e9);
        dist[k] = 0; // distance of source from source

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minh;
        minh.push({0, k}); // distance, source

        while(!minh.empty()){
            int u = minh.top().second;
            int d = minh.top().first;
            minh.pop();

            for(auto& it : adj[u]){
                int v = it.first;
                int wt = it.second;

                if(d + wt < dist[v]){
                    dist[v] = d + wt;
                    minh.push({dist[v], v});
                }
            }
        }

        int ansTime = INT_MIN;
        for(int i=1; i<n+1; i++){
            if(dist[i] == 1e9){
                return -1;
            }
            ansTime = max(ansTime, dist[i]);
        }

        return ansTime;
    }
};