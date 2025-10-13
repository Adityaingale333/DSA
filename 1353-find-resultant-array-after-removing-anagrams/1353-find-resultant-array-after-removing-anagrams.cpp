class Solution {
public:
    bool isAnagram(string s1, string s2){
        if(s1.length() != s2.length()) return false;
        vector<int> freq(26);

        for(int i=0; i<s1.length(); i++){
            freq[s1[i]-'a']++;
        }

        for(int i=0; i<s2.length(); i++){
            freq[s2[i]-'a']--;
        }

        for(int i=0; i<freq.size(); i++){
            if(freq[i] != 0){
                return false;
            }
        }

        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();

        vector<string> result;
        result.push_back(words[0]);

        for(int i=1; i<n; i++){
            if(isAnagram(words[i], result.back())){
                continue;
            }
            result.push_back(words[i]);
        }

        return result;
    }
};