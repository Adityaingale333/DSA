class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = 0;

        for(int i=0; i<n; i++){
            vector<int> freq(26, 0);
            for(int j=i; j<n; j++){
                freq[s[j] - 'a']++;

                int common = 0;
                bool check = true;
                for(int k=0; k<26; k++){
                    if(freq[k] == 0){
                        continue;
                    }
                    if(common == 0){
                        common = freq[k];
                    }
                    else if(freq[k] != common){
                        check = false;
                        break;
                    }
                }

                if(check){
                    maxLen = max(maxLen, j-i+1);
                }
            }
        }
        return maxLen;
    }
};