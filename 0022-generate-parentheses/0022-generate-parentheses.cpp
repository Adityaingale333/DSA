class Solution {
public:
    void solve(int open, int close,  int n, string& curr, vector<string>& ans){
        if(curr.length() == 2*n){
            ans.push_back(curr);
            return;
        }

        if(open < n){
            curr.push_back('(');
            solve(open+1, close, n, curr, ans);
            curr.pop_back();
        }

        if(close < open){
            curr.push_back(')');
            solve(open, close+1, n, curr, ans);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        int open = 0, close = 0;
        solve(open, close, n, curr, ans);
        return ans;
    }
};