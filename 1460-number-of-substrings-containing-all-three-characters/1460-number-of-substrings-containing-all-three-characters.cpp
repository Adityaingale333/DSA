class Solution {
public:
// We maintain a frequency vector mp(3,0) that keeps track of the counts of 'a', 'b', and 'c' in the current window.
// Two pointers (i and j):
// j expands the window by including new characters from s.
// i contracts the window to count valid substrings.
// When we find a substring that contains at least one 'a', 'b', and 'c':
// All substrings that start at i and end at j, j+1, ..., n-1 are valid (since increasing j further keeps the substring valid).
// We add (n - j) to result because all substrings from i to j, j+1, ..., n-1 are counted.
// We move i forward to continue counting more possible substrings.
    int numberOfSubstrings(string s) {
        int n = s.length();
        int result = 0;

        vector<int> mp(3,0); // a->0, b->1, c->2

        int i = 0;
        int j = 0;

        while(j<n){
            char ch = s[j];
            mp[ch-'a']++;

            while(mp[0] > 0 && mp[1] > 0 && mp[2] > 0){
                result = result + (n-j);

                mp[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return result;
    }
};