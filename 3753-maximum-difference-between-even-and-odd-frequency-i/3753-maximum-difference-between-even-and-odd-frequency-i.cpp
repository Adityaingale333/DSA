class Solution {
public:
    int maxDifference(string s) {
        int n = s.size();

        vector<int> freq(26, 0); // index represents letters

        for(int i=0; i<n; i++){
            freq[s[i]-'a']++; 
        }

        int maxOdd = 0;
        int maxEven = n+1;
        for(int i=0; i<26; i++){
            if(freq[i] == 0) continue;

            if(freq[i]%2 == 0){
                maxEven = min(maxEven, freq[i]);
            }

            else{
                maxOdd = max(maxOdd, freq[i]);
            }
        }

        return maxOdd-maxEven ;
    }
};