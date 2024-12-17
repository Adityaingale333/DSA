class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();

        if(t.size() > n) return "";

        unordered_map<char, int> mp;
        // store in map
        for(char &ch : t){
            mp[ch]++;
        }
        
        int requiredCount = t.size();
        int i=0, j=0;
        int minWindowSize = INT_MAX;
        int starti = 0;

        while(j < n){
            char ch = s[j];

            if(mp[ch] > 0){
               requiredCount--;
            }

            mp[ch]--; 

            while(requiredCount == 0){
                int currWindowSize = j-i+1;
                if(minWindowSize > currWindowSize){
                    minWindowSize = currWindowSize;
                    starti = i;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0){
                    requiredCount++;
                }
                i++;
            }
            j++;
        }

        return minWindowSize == INT_MAX ? "" : s.substr(starti, minWindowSize);
    }
};