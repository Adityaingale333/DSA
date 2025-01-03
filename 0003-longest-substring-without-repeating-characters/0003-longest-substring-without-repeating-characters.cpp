class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> mpp;

        int l=0, r=0;
        int len = 0;
        int max_len = 0;
        while(r<n){
            if(mpp.find(s[r]) != mpp.end() && mpp[s[r]] >= l){
                l = mpp[s[r]] + 1;
            }
            len = r-l+1;
            max_len = max(max_len,len);
            mpp[s[r]] = r;
            r++;
        }
        return max_len;
    }
};