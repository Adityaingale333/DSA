class Solution {
public:
    bool check(stack<char> st, string part, int n){
        for(int i=n-1; i>=0; i--){
            if(st.top() != part[i]){
                return false;
            }
            st.pop();
        }
        return true;
    }

    string removeOccurrences(string s, string part) {
        int n = s.size();
        int m = part.size();

        stack<char> st;

        for(int i=0; i<n; i++){
            st.push(s[i]);

            if(st.size() >= m && check(st, part, m) == true){
                for(int j=0; j<m; j++){
                    st.pop();
                }
            }
        }

        string ans = "";
        while(!st.empty()){
            ans = ans + st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};