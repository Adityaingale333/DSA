class Solution {
public:
    void solve(int i, vector<int>& temp, int sum, int target, vector<vector<int>>& ans, vector<int>& candidates){
        if(sum == target){
            ans.push_back(temp);
            return;
        }
            
        if(sum > target || i == candidates.size()) return;
        temp.push_back(candidates[i]);
        sum += candidates[i];
        solve(i+1, temp, sum, target, ans, candidates);

        sum -= candidates[i];
        temp.pop_back();

        int idx = i+1;
        while(idx < candidates.size() && candidates[idx]==candidates[idx-1]){
            idx++;
        }
        solve(idx, temp, sum, target, ans, candidates);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int i=0, sum = 0;
        solve(i, temp, sum, target, ans, candidates);
        return ans;
    }
};