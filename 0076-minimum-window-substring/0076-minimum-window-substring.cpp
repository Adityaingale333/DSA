class Solution {
public:
 /*1. Build a frequency map of t.
   2. Use a sliding window (i and j) over s.
   3. Expand the window to include valid characters (j++).
   4. Shrink the window when all characters of t are matched (i++), keeping track of the smallest valid window.
   5. Return the smallest valid substring or "" if no valid window exists.*/
    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char,int> mp;

        for(char& ch:t){
            mp[ch]++;
        }

        int l=0, r=0;
        int requiredCount = t.size(); // size of t, bcz we have to check that much characters only present in t
        int startl = 0; // to get the substring from where the smallest window will start
        int min_WindowSize = INT_MAX;

        while(r<n){
            char ch = s[r];
            if(mp[ch] > 0){
                requiredCount--;
            }
            mp[ch]--;
            while(requiredCount==0){
                int windowSize = r-l+1;
                if(min_WindowSize > windowSize){
                    min_WindowSize = windowSize;
                    startl = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0){
                    requiredCount++;
                } 
                l++;
            }
            r++;
        }
        return min_WindowSize == INT_MAX ? "" : s.substr(startl, min_WindowSize);
    }
};