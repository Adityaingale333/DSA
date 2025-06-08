class Solution {
public:
    char solve(vector<char>& vec, char op){
        if(op == '&'){
            for(int i=0; i<vec.size(); i++){
                if(vec[i] == 'f') return 'f';
            }
            return 't';
        }

        if(op == '|'){
            for(int i=0; i<vec.size(); i++){
                if(vec[i] == 't') return 't';
            }
            return 'f';
        }

        return vec[0] == 't' ? 'f' : 't';
    }
    bool parseBoolExpr(string s) {
        int n = s.size();

        stack<char> st;

        for(int i=0; i<n; i++){
            if(s[i] == ','){
                continue;
            }
            if(s[i] == ')'){
                vector<char> vec;
                while(st.top() != '('){ // close bracket mila
                    vec.push_back(st.top()); // brackets ke bich wale element
                    st.pop(); // open bracket pop kiya
                }
                st.pop(); // open bracket pop kiya

                char evaluation;
                evaluation = solve(vec, st.top()); // operator aur vector bheja
                st.pop();// operator pop kiya

                st.push(evaluation);
            }
            else{
                st.push(s[i]);
            }
            
        }
        return st.top() == 't' ? true : false;
    }
};