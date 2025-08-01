class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size();
        int m = trainers.size();

        sort(players.begin(), players.end()); // O(nlogn)
        sort(trainers.begin(), trainers.end()); // O(mlogm)

        int i=0, j=0;
        int count = 0;

        while(i<n && j<m){ // O( max(n,m) )
            if(players[i] <= trainers[j]){
                count++;
                i++;
            }
            j++;
        }

        return count;
    }
};