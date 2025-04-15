class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        vector<int> freq(26,0);

// we keep track of most frequent char, and its frequency
// while constructing result we will first fill up this char alternately
// and then other characters
        int maxFreq = 0;
        char maxFreqChar;
        for(auto& it:s){
            freq[it-'a']++;

            if(freq[it-'a'] > maxFreq){
                maxFreq = freq[it-'a'];
                maxFreqChar = it;
            }

            if(freq[it-'a'] > (n+1)/2){
                return "";
            }
        }

        string ans(n, ' ');
        int i = 0;

// filling thew most frequent character (0, 2, 4, ...)
        while(freq[maxFreqChar - 'a'] > 0){
            ans[i] = maxFreqChar;
            freq[maxFreqChar - 'a']--;
            i = i+2;
        }

        for(int j=0; j<26; j++){
            while(freq[j] > 0){
    // we have filled the result from 0 in alternate ways, so if it goes out of bound
    //then we start filling from 1
    // Switch to odd indices if even ones are full
                if(i >= n){                      
                    i = 1; 
                }

                ans[i] = j+'a';
                freq[j]--;
                i += 2;
            }
        }
        return ans;
    }
};