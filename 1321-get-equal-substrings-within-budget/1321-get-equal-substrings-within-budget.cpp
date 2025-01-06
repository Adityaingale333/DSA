class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();

        int i=0, j=0;
        int length = 0;
        int max_len = 0;
        while(j<n){
            if(abs(s[j]-t[j]) <= maxCost ){
                length = j-i+1;
                max_len = max(max_len,length);
                maxCost = maxCost - abs(s[j]-t[j]) ;
                j++;
            }
            else{
                maxCost = maxCost + abs(s[i]-t[i]);
                i++;
            }
        }
        return max_len;
    }
};