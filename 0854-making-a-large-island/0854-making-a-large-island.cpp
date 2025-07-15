class DisjointSet{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);

        for(int i=0; i<n; i++){
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        DisjointSet ds(n*n);
        
        // connect all existing islands
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col] == 0) continue;

                int drow[] = {1, 0, -1, 0};
                int dcol[] = {0, 1, 0, -1};
                for(int i=0; i<4; i++){
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];

                    if(nrow < n && nrow >= 0 && ncol < n && ncol >= 0 && grid[nrow][ncol] == 1){
                        int nodeNo = row*n + col;
                        int adjNodeNo = nrow*n + ncol;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        // now calculate totalsize by converting every 0 to 1, and return the max
        int ans = 0;

        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col] == 1) continue;

                int drow[] = {1, 0, -1, 0};
                int dcol[] = {0, 1, 0, -1};

                set<int> components;

                for(int i=0; i<4; i++){
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];

                    if(nrow < n && nrow >= 0 && ncol < n && ncol >= 0 && grid[nrow][ncol] == 1){
                        components.insert(ds.findUPar(nrow*n + ncol));
                    }
                }
                int totalSize = 0;
                for(auto& it : components){
                    totalSize = totalSize + ds.size[it];
                }
                ans = max(ans, totalSize + 1); // +1 for the size of 0 itself we are converting
            }
        }

        // there might be a case where every cell is 1, so we need to return the size of that ulp
        for(int cellNo=0; cellNo<n*n; cellNo++){
            ans = max(ans, ds.size[ds.findUPar(cellNo)]);
        }

        return ans;
    }
};