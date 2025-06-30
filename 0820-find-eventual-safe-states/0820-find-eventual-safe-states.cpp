class Solution {
public:
    // safe node are those node which are not part of cycle and does not become part of cycle in any way
    // so we just need to find those nodes that are not part of cycle, and does not lead to cycle

    bool dfs(int u, vector<vector<int>>& adj, vector<int>& visited, vector<int>& pathVisited, vector<int>& check){
        visited[u] = 1;  // Mark node as visited
        pathVisited[u] = 1; // mark node as current path visited

        for(auto& v : adj[u]){
            // If the neighbor is visited and is in the current DFS path => a cycle is found
            if(visited[v] == 1 && pathVisited[v] == 1){
                check[u] = 0; // Mark current node as unsafe (part of cycle or leads to a cycle)
                return true; // it is a cycle
            }
            // If the neighbor is unvisited, do DFS recursively
            else if(visited[v] == 0){
                if(dfs(v, adj, visited, pathVisited, check) == true){
                    check[u] = 0; // This node leads to a cycle → unsafe
                    return true;
                }
            }
        }

        // If no cycle is detected from this node, it's safe
        check[u] = 1;

        //remove the node from current path
        pathVisited[u] = 0;

        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();

        vector<int> visited(n, 0);
        
        vector<int> pathVisited(n, 0);

        vector<int> check(n, 0); // to mark which nodes are safe

        for(int i=0; i<n; i++){
            if(visited[i] == 0){
                dfs(i, adj, visited, pathVisited, check);
            }
        }

        vector<int> safeNodes;

        for(int i=0; i<n; i++){
            if(check[i] == 1){
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};