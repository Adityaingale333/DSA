class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> mp;

        int l = 0;
        int r = 0;

        int len = 0;
        int maxlen = 0;

        while(r<n){
            if(mp.find(s[r]) != mp.end() && mp[s[r]] >= l){
                l = mp[s[r]] + 1;
            }
            len = r-l+1;
            maxlen = max(maxlen, len);
            mp[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};