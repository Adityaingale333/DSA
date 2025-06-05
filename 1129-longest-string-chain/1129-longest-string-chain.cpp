class Solution {
public:
    bool checkPossible(string& s1, string& s2){
        if(s1.length() != s2.length()+1){
            return false;
        }

        int first = 0;
        int second = 0;
        while(first < s1.size()){
            if(second < s2.size() && s1[first] == s2[second]){
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        if(first == s1.size() && second == s2.size()) return true;
        return false;
    }
    static bool comp(string& s1, string& s2){
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(), comp);

        vector<int> dp(n, 1);
        int len = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(checkPossible(words[i], words[j]) && dp[j]+1 > dp[i]){
                    dp[i] = dp[j] + 1;
                }
            }
            len = max(len, dp[i]);
        }
        return len;
    }
};