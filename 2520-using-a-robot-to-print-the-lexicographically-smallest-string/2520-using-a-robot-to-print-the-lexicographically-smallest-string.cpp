class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();

        vector<char> minChar(n);
        minChar[n-1] = s[n-1];
        for(int i=n-2; i>=0; i--){
            minChar[i] = min(s[i], minChar[i+1]);
        }

        string t = "";
        string ans = "";
        for(int i=0; i<n; i++){
            t.push_back(s[i]);
            
            char min = (i+1 < n) ? minChar[i+1] : s[i];

            while(!t.empty() && t.back() <= min){
                ans.push_back(t.back());
                t.pop_back();
            }
        }

        while(!t.empty()){
            ans.push_back(t.back());
            t.pop_back();
        }
        return ans;
    }
};