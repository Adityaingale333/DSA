class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        stack<char> st;

        int count = 1;
        string num = "";
        for(int i=0; i<=n; i++){ // Loop goes to n (not n-1) to handle last number
            st.push(count + '0');

            // If pattern[i] is 'I' or end of pattern, empty the stack
            if(i == n || pattern[i] == 'I'){
                while(!st.empty()){
                    num.push_back(st.top());
                    st.pop();
                }
            }

            count++; // only inc count if it is D and then empty it when I occurs
        }
        return num;
    }
};