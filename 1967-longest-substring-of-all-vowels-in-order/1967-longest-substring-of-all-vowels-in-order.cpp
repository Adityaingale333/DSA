class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.size();
        int currlen = 0;
        int maxlen = 0;
        int v_Count = 0;

        for(int r=0; r<n; r++){
            if(r>0 && word[r] < word[r-1]){
                v_Count = 1;
                currlen = 0;
            }
            currlen++;
            if(r==0 || word[r] > word[r-1]){
                v_Count++;
            }
            if(v_Count==5){
                maxlen = max(maxlen,currlen);
            }
        }
        return maxlen;
    }
};