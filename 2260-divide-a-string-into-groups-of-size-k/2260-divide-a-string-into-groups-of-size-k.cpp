class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        vector<string> ans;

        if(n % k == 0){
            for(int i=0; i<n; i+=k){
                ans.push_back(s.substr(i, k));
            }
            return ans;
        }

        int remChar = n % k;
        for(int i=0; i<n-remChar; i+=k){ // jitne possible hai utne daal diye
            ans.push_back(s.substr(i, k));
        }

        string last = s.substr(n-remChar);
        while(last.length() != k){
            last = last + fill;
        }

        ans.push_back(last);
        return ans;
    }
};