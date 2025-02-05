class Solution {
public:
    bool allZero(unordered_map<char,int> freq){
        for(auto& [ch,count] : freq){
            if(count != 0){
                return 0;
            }
        }
        return 1;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        unordered_map<char,int> freq;

        for(auto& ch : p){
            freq[ch]++;
        }

        int l=0, r=0;
        vector<int> ans;

        while(r < n){
            freq[s[r]]--;
            if(r-l+1 == p.size()){
                if(allZero(freq)){
                    ans.push_back(l);
                }
                freq[s[l]]++;
                l++;
            }
            r++;
        }
        return ans;
    }
};