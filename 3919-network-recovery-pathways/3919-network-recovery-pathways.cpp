class Solution {
public: // Binary search + Dijkstra

    // Binary Search Over Edge Weights:
    // 1. The main goal is to maximize the minimum edge weight (minWt) in a valid path. To achieve this, we perform a binary search on the potential values of minWt.
    //      We start with a search range from 1 (the smallest possible edge weight) to INT_MAX (the largest edge weight).
    // 2. Why binary search?: Binary search helps us efficiently narrow down the largest valid minimum edge weight in O(log(maxEdgeWt))
    //      Instead of checking all possible edge weights, binary search reduces the time complexity significantly.

    // Checking Valid Paths Using Dijkstra:
    // For each candidate minWt during the binary search, we need to check if there exists a valid path where:
    //   ->   All edges have a weight >= minWt (this is enforced by binary search).
    //   ->   The path does not exceed the total cost k.
    //   ->   All intermediate nodes must be online.

    bool dijkstra(int n, int minWt, unordered_map<int, vector<pair<int, int>>>& adj, long long k){
        vector<long long> dist(n, LLONG_MAX); // min dist to reach nodes
        dist[0] = 0; // source node 

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> minh;
        minh.push({0, 0}); // currDist, node

        while(!minh.empty()){
            int u = minh.top().second;
            long long d = minh.top().first;
            minh.pop();

            if(d > dist[u]) continue; // if we have already reached this node with a shorter dist than skip this path

            for(auto& it : adj[u]){
                int v = it.first;
                int wt = it.second;

                // 1. all wt in the path should be greater than equal to the minWt
                // 2. total cost should be less than equal to k
                // 3. if we got a shorter dist to reach node v 
                if( (wt >= minWt) && (d + wt <= k) && (d + wt < dist[v]) ){ 
                    dist[v] = d + wt;
                    minh.push({dist[v], v});
                }
            }
        }

        return dist[n-1] != LLONG_MAX; // if not LLONG_MAX means we have reached the last node, try more bigger minWt
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if((u == 0 || online[u] == true) && (v == n-1 || online[v] == true) && wt <= k){ // only consider those nodes which are online
                adj[u].push_back({v, wt});
            }
        }

        // binary search over possible minWt
        long long low = 0;
        long long high = LLONG_MAX;
        int ans = -1;

        while(low <= high){
            long long mid = low + (high - low)/2;

            if(dijkstra(n, mid, adj, k)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }
};


























