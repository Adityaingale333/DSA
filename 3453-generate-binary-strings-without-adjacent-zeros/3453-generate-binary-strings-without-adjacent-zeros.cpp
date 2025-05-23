class Solution {
public:
    void solve(int prev, int& n, string& curr, vector<string>& ans){
        // base case : string of n length formed
        if(curr.length() == n){
            ans.push_back(curr);
            return;
        }
        // try bot 0 and 1 with the condition
        // no two 0 can be grouped together
        if(prev == -1 || prev == 1){
            curr.push_back('0');
            solve(0, n, curr, ans);
            curr.pop_back();
        }

        // we can always try 1
        curr.push_back('1');
        solve(1, n, curr, ans);
        curr.pop_back();
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        string curr = "";
        int prev = -1;
        solve(prev, n, curr, ans);
        return ans;
    }
};