class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()) return false;
        
        int n = s.length();

        vector<int> sFreq(26, 0);
        vector<int> tFreq(26, 0);

        for(int i=0; i<n; i++){
            sFreq[s[i] - 'a']++;
            tFreq[t[i] - 'a']++;
        }

        return sFreq == tFreq;
    }
};