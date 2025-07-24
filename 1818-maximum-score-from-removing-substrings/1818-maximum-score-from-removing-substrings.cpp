class Solution {
public:
    int solve(string& s, string& matchStr, int val){
        int n = s.size();
        
        int i=0;

        // i -> write, j -> read
        // j pointer will read and give the character to i for storing int ith pointer
        // i pointer will take whatever character j gives, and then check if the last characters matches or not
        // if matches goes back to the index from where the matched str starts

        int count = 0; // pairs to be removed

        for(int j=0; j<n; j++){
            s[i] = s[j];
            i++;

            if(i >= 2 && s[i-2] == matchStr[0] && s[i-1] == matchStr[1]){
                i = i-2;
                count++;
            }
        }

        s.erase(s.begin()+i, s.end());

        return count * val;
    }
    int maximumGain(string s, int x, int y) {
        int n = s.size();

        int maxVal = (x >= y) ? x : y;
        int minVal = (x < y) ? x : y;

        string minStr = (x < y) ? "ab" : "ba";
        string maxStr = (x >= y) ? "ab" : "ba";

        int firstPass = solve(s, maxStr, maxVal);

        int secondPass = solve(s, minStr, minVal);

        return firstPass + secondPass;
    }
};