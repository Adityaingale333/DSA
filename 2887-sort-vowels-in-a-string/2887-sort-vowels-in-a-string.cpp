class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' ||
           ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }

        return false;
    }
    string sortVowels(string s) {
        int n = s.length();

        unordered_map<char, int> freq;

        for(int i=0; i<n; i++){
            if(isVowel(s[i])){
                freq[s[i]]++;
            }
        }
        
        string temp = "AEIOUaeiou";
        int j=0;

        for(int i=0; i<n; i++){
            if(isVowel(s[i])){
                while(freq[temp[j]] == 0){
                    j++;
                }

                s[i] = temp[j];
                freq[temp[j]]--;
            }
        }

        return s;
    }
};