class Solution {
public:
    void solve(int i, int target, vector<int>& temp, vector<vector<int>>& ans, vector<int>& candidates) {
    if (target == 0) {
        ans.push_back(temp);
        return;
    }
    if (target < 0 || i < 0) {  // If we go out of bounds or target becomes negative, return
        return;
    }

    // Include the current candidate
    temp.push_back(candidates[i]);
    solve(i - 1, target - candidates[i], temp, ans, candidates);  // Move backward
    temp.pop_back();

    // Skip duplicates: don't process the same number again in the same combination
    while (i - 1 >= 0 && candidates[i] == candidates[i - 1]) {
        i--;  // Skip duplicate candidates
    }

    // Move to the next unique candidate in the reverse direction
    solve(i - 1, target, temp, ans, candidates);
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());  // Sort the candidates
    int n = candidates.size();
    vector<vector<int>> ans;
    vector<int> temp;
    solve(n - 1, target, temp, ans, candidates);  // Start from the end of the list
    return ans;
}

};