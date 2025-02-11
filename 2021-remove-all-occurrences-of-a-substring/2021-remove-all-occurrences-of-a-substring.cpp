class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.size();
        string result = "";
        for(int i=0; i<n; i++){
            result = result + s[i];
            // s.substr(x) then substring will be from x -> end of string.
            if(result.size() >= part.size() && result.substr(result.size()-part.size()) == part){
                result.erase(result.length() - part.size());
            }
        }
        return result;
    }
};