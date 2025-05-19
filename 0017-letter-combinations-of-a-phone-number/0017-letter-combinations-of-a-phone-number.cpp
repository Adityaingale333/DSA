class Solution {
public:
    void solve(int idx, string& digits, string& temp, unordered_map<char, string>& mp, vector<string>& ans){
        if(idx >= digits.length()){
            ans.push_back(temp);
            return;
        }

        char ch = digits[idx];
        string s = mp[ch];
        for(int i=0; i<s.size(); i++){
            temp.push_back(s[i]);
            solve(idx+1, digits, temp, mp, ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0){
            return {};
        }
       unordered_map<char, string> mp;

       mp['2'] = "abc"; 
       mp['3'] = "def"; 
       mp['4'] = "ghi"; 
       mp['5'] = "jkl"; 
       mp['6'] = "mno"; 
       mp['7'] = "pqrs"; 
       mp['8'] = "tuv"; 
       mp['9'] = "wxyz"; 

       vector<string> ans;
       string temp = "";
       int idx = 0;
       solve(idx, digits, temp, mp, ans);
       return ans;
    }
};