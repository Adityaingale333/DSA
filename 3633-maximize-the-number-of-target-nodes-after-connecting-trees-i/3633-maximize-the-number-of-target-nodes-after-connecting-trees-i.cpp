class Solution {
public:
    int bfs(int curr, unordered_map<int, vector<int>>& adj, int d, int N){
        queue<pair<int, int>> que;
        que.push({curr, 0});
        vector<bool> visited(N, false);
        visited[curr] = true;

        int count = 0; // count target nodes
        while(!que.empty()){
            int currNode = que.front().first;
            int dist = que.front().second;
            que.pop();

            if(dist > d){
                continue;
            }

            count++; // include current node in targetnodes
            // visit neighbour of curr nodes
            for(auto& ngbr : adj[currNode]){
                if(!visited[ngbr]){
                    visited[ngbr] = true;
                    que.push({ngbr, dist+1});
                }
            } 
        }
        return count;
    }

    vector<int> findCount (vector<vector<int>>& edges, int d){
        int N = edges.size() + 1;

        // adjacency list
        unordered_map<int, vector<int>> adj;

        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> result(N);
        for(int i=0; i<N; i++){
            result[i] = bfs(i, adj, d, N);
        }

        return result;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        // nodes in tree 1
        int N = edges1.size() + 1;
        
        // stores targetnodes count from each node in tree 1 within k distance
        vector<int> result1 = findCount(edges1, k);

        // stores targetnodes count from each node in tree 2 within k-1 distance
        vector<int> result2 = findCount(edges2, k-1);

        int maxTargetNodesCount = *max_element(result2.begin(), result2.end());

        for(int i=0; i<result1.size(); i++){
            result1[i] = result1[i] + maxTargetNodesCount;
        }

        return result1;
    }
};