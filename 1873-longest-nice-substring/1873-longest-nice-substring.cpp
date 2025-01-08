class Solution {
public:
    string longestNiceSubstring(string s) {
        // Base case: If the string is too short, it cannot be nice
        if(s.size() < 2) return "";

        unordered_set<char> seen(s.begin(), s.end());

        // Find the first character that violates the "nice" condition
        for(int i=0; i<s.size(); i++){

            char c = s[i];

            // Split the string at the invalid character
            if(seen.count(tolower(c))==0 || seen.count(toupper(c))==0){
                string left = longestNiceSubstring(s.substr(0,i));
                string right = longestNiceSubstring(s.substr(i+1));

                // Return the longer "nice" substring, or the left one if they are equal
                return left.size() >= right.size() ? left : right ;
            }
        }
        return s;
    }
};