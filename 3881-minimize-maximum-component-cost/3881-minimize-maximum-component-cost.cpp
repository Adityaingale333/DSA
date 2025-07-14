// 1. Sort the edges by weight in ascending order.
// 2. Build the MST using Kruskal’s algorithm (with your DisjointSet class using union by size).
// 3. Store the weights of the edges that are included in the MST.
// 4. To form k components, remove the k - 1 largest edges from the MST.
// 5. The maximum weight among the remaining MST edges is the maximum cost among all components.
// 6. If we remove more edges than available, we return 0 since all nodes are isolated or only single nodes remain.

// Time complexity: O(ElogE+E⋅α(N))
// where E is the number of edges, and α(N) is the inverse Ackermann function for DSU operations.
class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);

        for(int i=0; i<n+1; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }

        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] = size[ulp_v] + size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] = size[ulp_u] + size[ulp_v];
        }
    }
};

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        if(k >= n) return 0;

        vector<pair<int, pair<int,int>>> adj;
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj.push_back({wt, {u, v}});
        }

        sort(adj.begin(), adj.end());
        DisjointSet ds(n);

        vector<int> MSTwt;

        for(auto& it : adj){
            int u = it.second.first;
            int v = it.second.second;
            int wt = it.first;

            if(ds.findUPar(u) != ds.findUPar(v)){
                ds.unionBySize(u, v);
                MSTwt.push_back(wt);
            }
        }

        return MSTwt[MSTwt.size() - k];
    }
};