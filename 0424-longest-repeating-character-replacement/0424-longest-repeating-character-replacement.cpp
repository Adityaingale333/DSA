class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        vector<int> freq(26, 0); // A -> frequency

        int l=0, r=0;
        int maxFreq = 0;
        int ans = 0;

        while(r < n){
            freq[s[r] - 'A']++;

            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            while( (r-l+1) - maxFreq > k){
                freq[s[l] - 'A']--;

                for(int i=0; i<26; i++){
                    maxFreq = max(maxFreq, freq[i]); // keep updating maxFreq, after removing any character
                }

                l++;
            }

            ans = max(ans, r-l+1);
            r++;
        }

        return ans;
    }
};