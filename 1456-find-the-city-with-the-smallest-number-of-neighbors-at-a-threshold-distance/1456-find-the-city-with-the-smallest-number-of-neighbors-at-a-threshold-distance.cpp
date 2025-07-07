class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for(auto& edge : edges){
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }

        for(int i=0; i<n; i++){
            dist[i][i] = 0;
        }

        for(int via=0; via<=n-1; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][via] != 1e9 && dist[via][j] != 1e9){
                        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        }

        int countCity = n+1;
        int cityNo = -1;

        for(int city=0; city<n; city++){
            int count = 0;
            for(int adjCity = 0; adjCity<n; adjCity++){
                if(city != adjCity && dist[city][adjCity] <= distanceThreshold){
                    count++;
                }
            }
            if(count <= countCity){
                countCity = count;
                cityNo = city;
            }
        }
        return cityNo;
    }
};