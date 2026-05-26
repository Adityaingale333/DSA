class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();

        int lowerMask = 0;
        int upperMask = 0;

        for(int i=0; i<n; i++){
            if(islower(word[i])){
                lowerMask = lowerMask | (1 << (word[i] - 'a'));
            }
            else{
                upperMask = upperMask | (1 << (word[i] - 'A'));
            }
        }

        int common = lowerMask & upperMask;

        return __builtin_popcount(common);
    }
};