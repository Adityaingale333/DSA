class Solution {
public:
    void solve(int i, int target, vector<int>& temp, vector<vector<int>>& ans, vector<int>& candidates){
        if(target < 0 || i<0){
            return;
        }

        if(target == 0){
            ans.push_back(temp);
            return;
        }

        temp.push_back(candidates[i]);
        solve(i, target-candidates[i], temp, ans, candidates);
        temp.pop_back();
        

        solve(i-1, target, temp, ans, candidates);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        solve(n-1, target, temp, ans, candidates);
        return ans;
    }
};