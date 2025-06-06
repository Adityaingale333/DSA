class Solution {
public:
    /*int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& t){
        if(i > j){
            return 0;
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        int ans = INT_MAX;
        for(int k=i; k<=j; k++){ // this is looping over sorted cuts array
            int temp = cuts[j+1] - cuts[i-1] + solve(i, k-1, cuts, t) + solve(k+1, j, cuts, t);
            ans = min(ans, temp);
        }
        return t[i][j] = ans;
    }*/
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0); // now array becomes [0 1 3 4 5 7], where 0 and 7 is use to calculate length
        sort(cuts.begin(), cuts.end()); // so that we can cut properly
        int s = cuts.size(); 
        vector<vector<int>> t(s, vector<int>(s, 0));

        for(int i=s-2; i>=1; i--){
            for(int j=1; j<=s-2; j++){
                if(i > j) continue;
                int ans = INT_MAX;
                for(int k=i; k<=j; k++){ // this is looping over sorted cuts array
                    int temp = cuts[j+1] - cuts[i-1] + t[i][k-1] + t[k+1][j];
                    ans = min(ans, temp);
                }
                t[i][j] = ans;
            }
        }
        return t[1][s-2];
    }
};