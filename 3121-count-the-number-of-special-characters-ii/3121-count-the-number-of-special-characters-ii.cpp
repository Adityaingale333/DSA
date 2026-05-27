class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();

        unordered_map<char, vector<int>> mp;

        for(int i=0; i<n; i++){
            mp[word[i]].push_back(i);
        }

        unordered_set<char> st;

        for(int i=0; i<n; i++){
            if(islower(word[i]) && mp.count(toupper(word[i]))){
                int lenOfSmall = mp[word[i]].size();
                char c = toupper(word[i]);
                if(mp[word[i]][lenOfSmall-1] < mp[c][0]){
                    st.insert(word[i]);
                }
            }
        }

        return st.size();
    }
};