class Solution {
public:
    vector<int> encode(string& s){
        unordered_map<char, int> mp;
        vector<int> pattern;
        int idx = 0;
        
        for(char c : s){
            if(mp.find(c) == mp.end()){
                mp[c] = idx;
                idx++;
            }

            pattern.push_back(mp[c]);
        }

        return pattern;
    }
    bool isIsomorphic(string s, string t) {
        return encode(s) == encode(t);
    }
};