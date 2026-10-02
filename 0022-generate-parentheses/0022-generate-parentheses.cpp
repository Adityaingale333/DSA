class Solution {
public:
    void solve(int close, int open, string& temp, vector<string>& ans, int n){
        if(temp.size() == 2*n){
            ans.push_back(temp);
            return;
        }

        if(open < n){
            temp.push_back('(');
            solve(close, open+1, temp, ans, n);
            temp.pop_back();
        }

        if(close < open){
            temp.push_back(')');
            solve(close+1, open, temp, ans, n);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp = "";
        int close = 0;
        int open = 0;
        vector<string> ans;

        solve(close, open, temp, ans, n);

        return ans;
    }
};