class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        vector<int> count(26,0);
        string ans(n, '?');

        for(int i=0; i<n; i++){
            count[s[i] - 'a']++;
        }

        for(int i=0; i<26; i++){
            if(count[i] & 1){
                ans[n/2] = i + 'a';
                count[i]--;
                break;
            }
        }

        for(int i=0; i<26; i++){
            count[i] = count[i]/2;
        }

        int j = 0;
        for(int i=0; i<26; i++){
            while(count[i] > 0){
                ans[j] = ans[n-j-1] = i + 'a'; 
                count[i]--;
                j++;
            }
        }
        return ans;
    }
};