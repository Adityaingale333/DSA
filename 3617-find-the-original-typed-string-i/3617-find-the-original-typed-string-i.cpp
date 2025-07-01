class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();

        int possibleStrings = 1;
        unordered_map<char, int> freq; // char -> frequency of that char

        for(int i=0; i<n-1; i++){
            if(word[i] == word[i+1]){
                freq[word[i]]++;
            }
        }

        for(auto& it : freq){
            int count = it.second;
            possibleStrings = possibleStrings + count ;
        }

        return possibleStrings;
    }
};