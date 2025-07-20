class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        string s1 = strs[0];

        for(int k=1; k<n; k++){
            string s2 = strs[k];
            int i=0, j=0;

            while(i<s1.size() && j<s2.size()){
                if(s1[i] != s2[j]){
                    break;
                }
                i++, j++;
            }

            s1 = s1.substr(0, i);

            if(s1 == "") return "";
        }

        return s1;
    }
};