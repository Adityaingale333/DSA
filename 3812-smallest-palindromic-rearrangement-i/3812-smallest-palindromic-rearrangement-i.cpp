class Solution {
public:
// *** KEY OBSERVATION
// pallindrome string means first half of char will be same but reversed
// for even (abc | cba) , 
// if odd then (abc d cba) there will be single char which we can put in centre

    string smallestPalindrome(string s) {
        int n = s.length();
        vector<int> count(26,0);
        string ans(n, '?');
// count frequency of each character
        for(int i=0; i<n; i++){
            count[s[i] - 'a']++;
        }
// if odd length then we put that extra character in the centre
        for(int i=0; i<26; i++){
            if(count[i] & 1){
                ans[n/2] = i + 'a';
                count[i]--;
                break;
            }
        }
// halving all freq, bcz we only need to construct halg ans other half will same but reversed
        for(int i=0; i<26; i++){
            count[i] = count[i]/2;
        }
// we handle the lexicographically smallest by starting i from 0, so that it is 
// constructed in that way 
        int j = 0;
        for(int i=0; i<26; i++){
            while(count[i] > 0){
                ans[j] = ans[n-j-1] = i + 'a'; // ans[0] = ans[n-0-1], we fill two pos at a time
                count[i]--;
                j++;
            }
        }
        return ans;
    }
};