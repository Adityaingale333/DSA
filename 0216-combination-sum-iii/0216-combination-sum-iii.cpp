class Solution {
public:
    void solve(int i, vector<int>& temp, int sum, int n, vector<vector<int>>& ans, int k){
        if(temp.size() == k){
            if(sum == n){
                ans.push_back(temp);
            }
            return;
        }

        if(sum > n || temp.size() > k || i > 9) return;

        temp.push_back(i);
        sum += i;
        solve(i+1, temp, sum, n, ans, k);

        sum -= i;
        temp.pop_back();
        solve(i+1, temp, sum, n, ans, k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        int i = 1, sum = 0;
        solve(i, temp, sum, n, ans, k);
        return ans;
    }
};