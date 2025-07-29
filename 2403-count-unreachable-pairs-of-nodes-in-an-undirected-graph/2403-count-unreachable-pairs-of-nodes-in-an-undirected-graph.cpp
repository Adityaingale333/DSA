class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);

        for(int i=0; i<=n; i++){
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
    long long countPairs(int n, vector<vector<int>>& edges) {

        DisjointSet ds(n);

        for(int i=0; i<edges.size(); i++){
            ds.unionBySize(edges[i][0], edges[i][1]);
        }

        //int components = 0;

        long long ans = 0;
        int remainingNodes = n;

        for(int i=0; i<n; i++){
            if(ds.findUPar(i) == i){
                ans = ans + ( (long long)ds.size[i] * (remainingNodes - (long long)ds.size[i]) );
                remainingNodes = remainingNodes - ds.size[i];
                //components++;
            }
        }

        return ans;
    }
};