class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();

        if(n == 0) return s;

        int count = 1;
        char ch = s[0];

        string ans;
        ans.push_back(ch);

        for(int i=1; i<n; i++){
            if(s[i] == ch){
                count++;
            }
            else{
                ch = s[i];
                count = 1;
            }

            if(count > 2){
                continue;
            }

            ans.push_back(s[i]);
        }

        return ans;
    }
};