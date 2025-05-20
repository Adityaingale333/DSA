class Solution {
public:
    bool isPalindrome(string part){
        for(int i=0; i<part.size()/2; i++){
            if(part[i] != part[part.size()-i-1]){
                return false;
            }
        }
        return true;
    }
    void solve(vector<string>& temp, vector<vector<string>>& ans, string s){
        if(s.size() == 0){
            ans.push_back(temp);
            return;
        }

        for(int i=0; i<s.size(); i++){
            string part = s.substr(0, i+1);
            if(isPalindrome(part)){
                temp.push_back(part);
                solve(temp, ans, s.substr(i+1));
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(temp, ans, s);
        return ans;
    }
};