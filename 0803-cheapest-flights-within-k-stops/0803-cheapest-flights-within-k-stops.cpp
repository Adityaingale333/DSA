class Solution {
public:
    // we have source, destination, directed and weighted graph
    // so we will use dijkstra 

    // Dijkstra's algorithm (with a priority queue) is not directly applicable to this problem is
    // due to the restriction on the number of stops (k).  

    // Dijkstra's algorithm assumes that we are minimizing the distance or cost from a source node 
    // to a target node, regardless of the number of steps or hops (edges) involved.
    
    // Dijkstra's algorithm doesn’t have an inherent mechanism to limit the number of stops
    // —> it just keeps exploring all edges until the target is found, potentially violating the stop constraint.

    // So we will use a MODIFIED DIJKSTRA approach, where we will prioritize STOPS more than dist
    // so we will use queue, bcz we will going forward as stop1 stop2 then stop3
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        unordered_map<int, vector<pair<int,int>>> adj;
        for(auto& edge : flights){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            // u -> v,wt
            adj[u].push_back({v, wt});
        }

        queue<pair<int, pair<int,int>>> q; // {node, {src, dist}}
        q.push({0, {src, 0}});

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while(!q.empty()){
            int stops = q.front().first;
            int u = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();

            if(stops > k) continue; // no need to go further, try other iteration

            for(auto& it : adj[u]){
                int v = it.first;
                int wt = it.second;

                if(cost + wt < dist[v] && stops <= k){
                    dist[v] = cost + wt;
                    q.push({stops + 1, {v, dist[v]}});
                }
            }
        }

        if(dist[dst] == 1e9) return -1;

        return dist[dst];
    }
};