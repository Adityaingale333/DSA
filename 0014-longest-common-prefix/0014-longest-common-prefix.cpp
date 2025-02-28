class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string prefix = strs[0];

        for(int i=1; i<n; i++){
            int j=0;

            // j < prefix and j < word we are comparing with and jab tak letters equal hai
            while(j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]){
                j++;
            }

            prefix = prefix.substr(0,j);

            if(prefix.empty()) break;
        }

        return prefix;
    }
};