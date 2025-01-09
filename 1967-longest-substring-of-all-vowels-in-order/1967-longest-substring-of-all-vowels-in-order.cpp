class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.size();
        int vowel = 0;
        int currlen = 0;
        int maxlen = 0;

        for(int i=0; i<n; i++){
            if(i>0 && word[i] < word[i-1]){
                currlen = 0;
                vowel = 1;
            }

            currlen++;

            if(i==0 || word[i] > word[i-1]){
                vowel++;
            }
            if(vowel == 5){
                maxlen = max(maxlen, currlen);
            }
        }
        return maxlen;
    }
};