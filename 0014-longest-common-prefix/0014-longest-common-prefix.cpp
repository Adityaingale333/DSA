class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        sort(strs.begin(), strs.end(), [](string& s1, string&s2){
            return s1.length() < s2.length();
        });

        string s1 = strs[0];
        int minIdx = INT_MAX;

        for(int k=1; k<n; k++){
            string s2 = strs[k];
            int i=0, j=0;

            while(i<s1.size() && j<s2.size()){
                if(s1[i] != s2[j]){
                    if(i==0) i = INT_MAX;
                    break;
                }
                i++, j++;
            }

            minIdx = min(minIdx, i);
        }

        return minIdx == INT_MAX ? "" : s1.substr(0, minIdx);
    }
};