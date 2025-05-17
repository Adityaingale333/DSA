class Solution {
public:
    void solve(int i, vector<int> temp, int sum, int target, vector<int>& candidates, vector<vector<int>>& ans){
        if(i == candidates.size()){
            if(sum > target) return;
            if(sum == target){
                ans.push_back(temp);
            }
            return;
        }

        if(candidates[i] + sum <= target){
            temp.push_back(candidates[i]);
            sum += candidates[i];
            solve(i, temp, sum, target, candidates, ans);

            sum -= candidates[i];
            temp.pop_back();
        }

        solve(i+1, temp, sum, target, candidates, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int i = 0;
        int sum = 0;
        solve(i, temp, sum, target, candidates, ans);
        return ans;
    }
};