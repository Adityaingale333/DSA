class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n = text.length();

        vector<int> broken(26, 0);
        for(int i=0; i<brokenLetters.size(); i++){
            broken[brokenLetters[i]-'a']++;
        }

        int count = 0;

        int i=0;
        while(i < n){
            bool isBroken = false;
            while(i<n && text[i] != ' '){
                if(broken[text[i]-'a'] != 0){
                    isBroken = true;
                }
                i++;
            }
            if(!isBroken){
                count++;
            }
            i++;
        }

        return count;
    }
};