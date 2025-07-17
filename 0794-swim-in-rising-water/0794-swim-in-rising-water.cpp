// one more way of solving it is using DSU
// we can consider each cell as a node, and then sort them in elevation order
// sorting will help us to acces the cell in sorted order and then activate them one by one
// we will mark them visited and then while traversing we will unio it with already activated neighbours
// we then check if (0, 0) and (n-1, n-1) are connected, the first time this happens it means there is a path between them 
class DisjointSet{
public:
    vector<int> parent, size;
    DisjointSet(int n){
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

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> visited(n*n, 0);

        DisjointSet ds(n*n);

        vector<pair<int, pair<int,int>>> nodes;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                nodes.push_back({grid[i][j], {i, j}});
            }
        }

        sort(nodes.begin(), nodes.end()); // sort acc to elevation

        for(auto& it : nodes){
            int row = it.second.first;
            int col = it.second.second;
            int elevation = it.first;

            int nodeNo = row*n + col;
            
            visited[nodeNo] = 1;

            int drow[] = {1, 0, -1, 0};
            int dcol[] = {0, 1, 0, -1};
            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                int adjNodeNo = nrow*n + ncol;

                if(nrow < n && nrow >= 0 && ncol < n && ncol >= 0 && visited[adjNodeNo] == 1){
                    ds.unionBySize(nodeNo, adjNodeNo);
                }
            }

            if(ds.findUPar(0) == ds.findUPar((n*n)-1)){
                return elevation;
            }
        }

        return -1;
    }
};