class Solution {
public:
    int n;
    int t[301];
    bool solve(int idx, string& s, unordered_set<string>& st){
        if(idx == n){
            return true;
        }

        if(t[idx] != -1){
            return t[idx];
        }

        if(st.find(s.substr(idx, n-idx)) != st.end()){
            return t[idx] = true;
        }

        for(int l=1; l<n; l++){
            string temp = s.substr(idx, l);
            if(st.find(temp) != st.end() && solve(idx + l, s, st)){
                return t[idx] = true;
            }
        }
        return t[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        
        memset(t, -1, sizeof(t));

        unordered_set<string> st;

        for(string& word : wordDict){
            st.insert(word);
        }

        return solve(0, s, st);
    }
};