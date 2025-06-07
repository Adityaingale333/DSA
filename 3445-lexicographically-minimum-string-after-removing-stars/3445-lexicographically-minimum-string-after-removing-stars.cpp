class Solution {
public:
    string clearStars(string s) {
        int n = s.size();

        vector<vector<int>> mp(26); // mapping of characters == a -> 0,1,3   b-> 2
        // whenever we encounter a star we iterate in the map from a to z and remove the last elemwnt from their vec

        vector<int> to_Remove(n, 0);

        for(int i=0; i<n; i++){
            if(s[i] == '*'){
                for(char ch='a'; ch<='z'; ch++){
                    if(mp[ch-'a'].size() != 0){
                        to_Remove[mp[ch-'a'].back()] = 1;
                        mp[ch-'a'].pop_back();
                        break;
                    }
                }
            }
            else{
                mp[s[i]-'a'].push_back(i);
            }
        }

        string ans;
        for(int i=0; i<n; i++){
            if(to_Remove[i] != 1 && s[i] != '*'){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};