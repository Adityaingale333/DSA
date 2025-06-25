class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int& n, int i, vector<int>& t){
        if(i >= n){
            return 0;
        }

        if(t[i] != -1){
            return t[i];
        }

        // cost of 1 day pass
        int cost1 = costs[0] + solve(days, costs, n, i+1, t);

        // cost of 7 day pass
        int j = i;
        int max_day = days[i] + 7;
        while(j < n && days[j] < max_day){
            j++;
        }
        int cost7 = costs[1] + solve(days, costs, n, j, t);

        // cost of 39 day pass
        j = i;
        max_day = days[i] + 30;
        while(j<n && days[j] < max_day){
            j++;
        }
        int cost30 = costs[2] + solve(days, costs, n, j, t);

        return t[i] = min({cost1, cost7, cost30});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> t(n, -1);
        return solve(days, costs, n, 0, t);
    }
};