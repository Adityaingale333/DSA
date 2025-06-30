class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;

        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);

        for(auto& edge : prerequisites){
            int a = edge[0];
            int b = edge[1];

            // b --> a
            adj[b].push_back(a);

            // arrow a ki taraf jaa raha hai
            indegree[a]++;
        }

        queue<int> q;

        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> courseOrder;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            courseOrder.push_back(u);

            for(auto& v : adj[u]){
                indegree[v]--;

                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        if(courseOrder.size() < n) return {};
        
        return courseOrder;
    }
};