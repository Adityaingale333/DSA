class Solution {
public:
    bool allZero(vector<int>& counter){
        for(auto& i:counter){
            if(i != 0) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        vector<int> freq(26,0);

        for(int i=0; i<p.size(); i++){
            char ch = p[i];
            freq[ch-'a']++;
        }

        int i=0, j=0;
        vector<int> ans;

        while(j<n){
            freq[s[j]-'a']--;
            if(j-i+1 == p.size()){
                if(allZero(freq)){
                    ans.push_back(i);
                }
                freq[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return ans;
    }
};