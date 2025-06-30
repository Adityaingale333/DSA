class Solution {
public:
    // its asking us to do topological sort
    // linear ordering of vertices, of DAG where for every edge uv, vertex u comes before v
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;

        unordered_map<int, vector<int>> adj; // adjacency list

        for(auto& edge : prerequisites){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        vector<int> indegree(n, 0); // indegree vector, how many incoming nodes on ith node

        for(int u=0; u<n; u++){
            for(auto& v : adj[u]){
                indegree[v]++;
            }
        }

        queue<int> q;

        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int count = 0; // instead of topo vector, just use a counter, if it is not possible then it will never reach n
        while(!q.empty()){
            int u = q.front();
            q.pop();

            count++;
            for(auto& v : adj[u]){
                indegree[v]--; // u will go to these v, so indegree of v will be reduced by one

                if(indegree[v] == 0){ // if indegree becomes 0, push it in the queue
                    q.push(v);
                }
            }
        }

        if(count == n) return true;

        return false;
    }
};