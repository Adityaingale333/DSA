class Solution {
public:
    int M = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        //unordered_map<char,int> mp;
        vector<int> mp(26,0);

        for(int i=0; i<s.length(); i++){ // O(n)
            mp[s[i]-'a']++;
        }

        for(int i=1; i<=t; i++){  // O(t) * O(26)
            //unordered_map<char,int> temp;
            vector<int> temp(26,0);
            for(int i=0; i<26; i++){  //O(26)
                char ch = i+'a';
                int freq = mp[i];
                if(ch != 'z'){
                    temp[(ch+1) - 'a'] = (temp[(ch+1) - 'a'] + freq) % M;
                }
                else{
                    temp['a' - 'a'] = (temp['a' - 'a'] + freq) % M;
                    temp['b' - 'a'] = (temp['b' - 'a'] + freq) % M;
                }
            }
            mp = move(temp);
        }

        int result = 0;
        for(int i=0; i<26; i++){ // O(26)
            result = (result + mp[i]) % M;
        }
        return result;
    }
};