class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> count(26,0);

        int maxFreq = 0;
        int maxFreqChar;
        for(auto& ch : s){
            count[ch-'a']++;

            if(count[ch-'a'] > maxFreq){
                maxFreq = count[ch-'a'];
                maxFreqChar = ch;
            }

            if(count[ch-'a'] > (n+1)/2){
                return "";
            }
        }

        string ans = s;
        int i = 0;

        while(count[maxFreqChar - 'a'] > 0){
            ans[i] = maxFreqChar;
            i = i+2;
            count[maxFreqChar - 'a']--;
        }

        for(char ch='a'; ch<='z'; ch++){
            while(count[ch-'a'] > 0){
                if(i >= n){
                    i = 1;
                }

                ans[i] = ch;
                i = i+2 ;
                count[ch-'a']--;
            }
        }
        return ans;
    }
};