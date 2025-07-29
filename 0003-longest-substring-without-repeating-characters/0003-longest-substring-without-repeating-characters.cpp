class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;

        int n = s.length();

        vector<int> freq(128, 0);

        int l=0, r=0;
        int ans = 0;

        while(r < n){
            freq[s[r]]++;

            while(freq[s[r]] > 1){
                freq[s[l]]--;
                l++;
            }

            ans = max(ans, r-l+1);
            r++;
        }

        return ans;
    }
};