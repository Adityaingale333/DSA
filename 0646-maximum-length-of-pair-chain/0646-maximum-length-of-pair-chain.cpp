class Solution {
public:
    int solve(int i, int l, int r, int idx, vector<vector<int>>& pairs, vector<vector<int>>& t){
        if(i < 0){
            return 0;
        }

        if(t[i][idx] != -1){
            return t[i][idx];
        }

        int notTake = solve(i-1, l, r, idx, pairs, t);

        int take = 0;
        if(idx == pairs.size() || pairs[i][r] < pairs[idx][l]){
            take = 1 + solve(i-1, l, r, i, pairs, t);
        }
        return t[i][idx] = max(take, notTake);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> t(n, vector<int>(n+1, -1));
        return solve(n-1, 0, 1, n, pairs, t); // n == idx, to start comparing
    }
};