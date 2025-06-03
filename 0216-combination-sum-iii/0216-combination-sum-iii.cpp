class Solution {
public:
    void solve(int i, int size, int sum, vector<int>& temp, vector<vector<int>>& ans){
        if(temp.size() == size){
            if(sum == 0){
                ans.push_back(temp);
            }
            return ;
        }
        if(i<1 || sum<0){
            return;
        }

        temp.push_back(i);
        solve(i-1, size, sum-i, temp, ans);
        temp.pop_back();

        solve(i-1, size, sum, temp, ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(9, k, n, temp, ans);
        return ans;
    }
};