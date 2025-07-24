class Solution {
public:
    int solve(string& s, string& matchStr, int val){
        int n = s.size();
        int i=0;

        stack<char> st;
        st.push(s[0]);

        int count = 0; // count of pair

        for(int i=1; i<n; i++){
            if(s[i] == matchStr[1] && !st.empty() && st.top() == matchStr[0]){
                st.pop();
                count++;
            }
            else{
                st.push(s[i]);
            }
        }

        string temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }

        reverse(temp.begin(), temp.end());

        s = temp;

        return count * val;
    }
    int maximumGain(string s, int x, int y) {
        int n = s.size();

        int maxVal = (x >= y) ? x : y;
        int minVal = (x < y) ? x : y;

        string minStr = (x < y) ? "ab" : "ba";
        string maxStr = (x >= y) ? "ab" : "ba";

        int firstPass = solve(s, maxStr, maxVal);

        int secondPass = solve(s, minStr, minVal);

        return firstPass + secondPass;
    }
};