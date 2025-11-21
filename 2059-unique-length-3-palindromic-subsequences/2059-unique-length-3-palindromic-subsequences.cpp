class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();

        int ans = 0;

        vector<int> taken(26, 0);

        for(int i=0; i<n-1; i++){
            if(taken[s[i]-'a'] == 1){
                continue;
            }
            taken[s[i]-'a'] = 1;
            unordered_set<int> st;
            int maxEl = 0;
            for(int j=i+1; j<n; j++){
                if(s[i] == s[j] && j-i+1 >= 3){
                    maxEl = st.size();
                }
                st.insert(s[j]);
            }
            ans = ans + maxEl;
        }

        return ans;
    }
};