class Solution {
public:
    bool isVowel(char c){
        c = tolower(c);

        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return true;
        }

        return false;
    }
    string reverseVowels(string s) {
        int n = s.length();

        int i=0, j=n-1;

        while(i < j){
            while(i<j && !isVowel(s[i])){
                i++;
            }

            while(j>i && !isVowel(s[j])){
                j--;
            }

            swap(s[i], s[j]);
            i++, j--;
        }

        return s;
    }
};