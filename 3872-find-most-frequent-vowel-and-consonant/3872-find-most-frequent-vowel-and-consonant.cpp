class Solution {
public:
    int maxFreqSum(string s) {
        int n = s.size();

        vector<int> freq(26, 0);

        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
        }

        int maxVowel = 0;
        int maxCon = 0;

        for(int i=0; i<freq.size(); i++){
            if(i == 0 || i == 4 || i == 8 || i == 14 || i == 20){
                maxVowel = max(maxVowel, freq[i]);
            }
            else{
                maxCon = max(maxCon, freq[i]);
            }
        }

        return maxVowel + maxCon;
    }
};