class Solution {
public:
    // bipartite means, can we divide the graph into two colours, such that no adjacent nodes are of same colour
    bool dfs(int curr, vector<vector<int>>& graph, vector<int>& color, int currColor){
        color[curr] = currColor;

        for(auto& v : graph[curr]){

            if(color[curr] == color[v]){ // if the neighbour is already coloured, and it is same as curr, and it is not bipartite
                return false;
            }

            else if(color[v] == -1){ // means this neighbour is not colored
                int colorOfV = 1 - currColor; // if already 0 then -> 1-0 = 1, else if already 1 then -> 1-1 = 0 
                bool check = dfs(v, graph, color, colorOfV);
                if(check == false) return false; // written in simiplified form
            }

        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();

        vector<int> color(n, -1); // red = 0, green = 1

        for(int i=0; i<n; i++){
            if(color[i] == -1){

                if(dfs(i, graph, color, 0) == false){ // 0 -> means i am colouring red 
                    return false;
                } 

            }
        }
        return true;
    }
};