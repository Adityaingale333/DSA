class Solution {
public:
  //  Here we are passing the map by reference bcz this makes the code efficient
  //  and does not create a copy of the map freq every time the function is called
  //  and to avoid te changes to be done in this function, we use "const" which does 
  //  does not aloow changes to be made  
    bool allZero(const unordered_map<char,int>& freq){
        for(auto& [ch,count] :freq){
            if(count!=0) return 0;
        }
        return 1;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        unordered_map<char,int> freq;

        for(int i=0; i<p.size(); i++){
            freq[p[i]]++;
        }

        int l=0, r=0;
        vector<int> ans;
        while(r<n){
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