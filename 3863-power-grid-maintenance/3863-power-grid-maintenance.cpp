class Solution {
public:
    void dfs(int u, unordered_map<int, vector<int>>& adj, vector<int>& visited, unordered_map<int, set<int>>& componentsElement, int id, vector<int>& nodeId){
        visited[u] = 1;
        componentsElement[id].insert(u);

        for(auto& v : adj[u]){
            if(!visited[v]){
                nodeId[v] = id;
                dfs(v, adj, visited, componentsElement, id, nodeId);
            }
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for(auto& it : connections){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(c+1, 0);

        unordered_map<int, set<int>> componentsElement;
        vector<int> nodeId(c+1, 0);

        for(int i=1; i<=c; i++){
            if(!visited[i]){
                nodeId[i] = i;
                dfs(i, adj, visited, componentsElement, i, nodeId);
            }
        }
        
        vector<int> ans;

        for(auto& it : queries){
            int component = nodeId[it[1]];

            if(it[0] == 2){
                componentsElement[component].erase(it[1]);
                continue;
            }

            if(componentsElement[component].find(it[1]) != componentsElement[component].end()){
                ans.push_back(it[1]);
            }
            else if(componentsElement[component].empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(*componentsElement[component].begin());
            }
        }

        return ans;
    }
};