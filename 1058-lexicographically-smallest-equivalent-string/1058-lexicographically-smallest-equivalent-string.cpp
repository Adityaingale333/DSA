class Solution {
public:
    int parent(int x, vector<int>& P){
        if(P[x] == x){
            return x;
        }

        return P[x] = parent(P[x], P);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();

        vector<int> P(26, 0);

        for(int i=0; i<26; i++){
            P[i] = i;
        }

        for(int i=0; i<n; i++){
            int pa = parent(s1[i] - 'a', P);
            int pb = parent(s2[i] - 'a', P);
            if(pa < pb) P[pb] = pa;
            else P[pa] = pb;
        }
        string ans;
        for(int i=0; i<baseStr.size(); i++){
            char ch = parent(baseStr[i]-'a', P) + 'a';
            ans.push_back(ch);
        }
        return ans;
    }
};