class Solution {
public:
//Maintain an array lastseen to store the last index of each character ('a', 'b', 'c'), 
//and update it as you iterate through the string.
//For each index i, if all three characters are seen (lastseen[0], lastseen[1], lastseen[2] ≠ -1), 
//add min(lastseen[0], lastseen[1], lastseen[2]) + 1 to the result.
    int numberOfSubstrings(string s) {
       int n = s.size();
       int lastseen[3] = {-1, -1, -1};
       int ans = 0;

       for(int i=0; i<n; i++){
            lastseen[s[i]-'a'] = i;
            if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1) {
                ans = ans + min(lastseen[0], min(lastseen[1], lastseen[2])) + 1;
            }       
        }
        return ans;
    }
};