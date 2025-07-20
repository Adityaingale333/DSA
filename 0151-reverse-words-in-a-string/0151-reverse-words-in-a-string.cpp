class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();

        stringstream SS(s);

        string token;
        string ans;

        while(SS >> token){
            ans = token + ' ' + ans;
        }

        return ans.substr(0, ans.size()-1);
    }
};