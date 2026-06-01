class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();

        sort(cost.begin(), cost.end());

        int j = n-3;
        int ans = 0;
        
        for(int i=n-1; i>=0; i--){
            if(i == j){
                j = j-3;
                continue;
            }
            ans += cost[i];
        }

        return ans;
    }
};