class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size();
        int i=0;
        unordered_map<string,int> substringCount;
        unordered_map<char,int> charCount;
        int uniqueChar = 0;
        int max_occurence = 0;

        while(i<n){
            // Add the current character to the window
            charCount[s[i]]++;
            if(charCount[s[i]] == 1){
                uniqueChar++;
            }

            // Remove the character that's sliding out of the window
            if(i >= minSize){
                charCount[s[i - minSize]]--;
                if(charCount[s[i - minSize]] == 0){
                    uniqueChar--;
                }
            }
            // Check if the current window satisfies the constraints
            if(uniqueChar<=maxLetters && i>=minSize-1){
                string substring = s.substr(i-minSize+1, minSize);
                substringCount[substring]++;
                max_occurence = max(max_occurence, substringCount[substring]);
            }
            i++;
        }
        return max_occurence;
    }
};