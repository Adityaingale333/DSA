class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();

        int i=0, j=0;
        int max_len = 0;
        int currCost = 0;
        while(j<n){
            currCost = currCost + abs(s[j]-t[j]);

            while(currCost > maxCost){
                currCost = currCost - abs(s[i]-t[i]);
                i++;
            }

            max_len = max(max_len, j-i+1);

            j++;
        }
        return max_len;
    }
};