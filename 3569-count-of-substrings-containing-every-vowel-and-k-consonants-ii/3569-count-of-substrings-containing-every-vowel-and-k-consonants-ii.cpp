class Solution {
public:
// Expand the window (j moves forward).
// Track vowels using an unordered_map.
// Track consonant count separately (cons).
// If cons > k, shrink the window from i.
// If map.size() == 5 (all vowels present) and cons == k, count substrings.
    bool isVowel(char &ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'; 
    }

    long long countOfSubstrings(string word, int k) {
        int n = word.length();

        unordered_map<char, int> map; // to keep count of vowels

        vector<int> nextCons(n); //Stores the next consonant index after each position.
        int lastConsIdx = n;
        for(int i=n-1; i>=0; i--){
            nextCons[i] = lastConsIdx;
            if(!isVowel(word[i])){
                lastConsIdx = i;
            }
        } 

        int i = 0;
        int j = 0;
        long long count = 0;
        int cons = 0;
        while(j<n){
            char ch = word[j];
            if(isVowel(ch)){
                map[ch]++;
            }
            else{
                cons++;
            }

            //cons must always be k, if it is greater than k then it is invalid
            while(cons > k){ // invalid window
                char ch = word[i];
                if(isVowel(ch)){
                    map[ch]--;
                    if(map[ch] == 0){
                        map.erase(ch);
                    }
                }
                else{
                    cons--;
                }
                i++;
            }

            while(i<n && map.size() == 5 && cons == k){ // valid window
                int idx = nextCons[j]; // it will tell next consonant after jth index
                count = count + (idx - j); // count all substrings, from that index to, next valid index
                char ch = word[i];
                if(isVowel(ch)){
                    map[ch]--;
                    if(map[ch] == 0){
                        map.erase(ch);
                    }
                }
                else{
                    cons--;
                }
                i++;
            }
            j++;
        }
        return count;
    }
};