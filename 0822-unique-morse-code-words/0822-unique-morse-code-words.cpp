class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        int n = words.size();

        unordered_map<char, string> mp;
        unordered_set<string> st;

        vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.",
        "....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
        "...","-","..-","...-",".--","-..-","-.--","--.."} ;

        for(int i ='a'; i<='z'; i++){
            mp[i] = code[i-'a'];
        }

        for(auto& word : words){
            string transformation = "";
            for(auto& ch : word){
                transformation = transformation + code[ch-'a'];
            }
            st.insert(transformation);
        }
        return st.size();
    }
};