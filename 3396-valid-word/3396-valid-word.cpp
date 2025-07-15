class Solution {
public:
    bool isValid(string word) {
        int n = word.length();

        if(n < 3) return false;
        
        bool vowel = false;
        bool consonant = false;

        for(int i=0; i<n; i++){
            if(isalnum(word[i]) == false){ // allows only alphabets and digits, special characters will be take care here
                return false;
            }

            if(isalpha(word[i])){
                char ch = tolower(word[i]);
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                    vowel = true;
                }
                else{
                    consonant = true;
                }
            }
        }
        return vowel && consonant;
    }
};