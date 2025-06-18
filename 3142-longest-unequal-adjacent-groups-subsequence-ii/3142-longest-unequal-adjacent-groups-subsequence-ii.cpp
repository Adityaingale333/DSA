class Solution {
public:
    bool checkHammingDist(string& s1, string& s2){
        int n = s1.size();
        int count = 0;
        for(int i=0; i<n; i++){
            if(s1[i] != s2[i]){
                count++;
                if(count > 1){
                    return false;
                }
            }
        }
        return count == 1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();

        vector<int> dp(n, 1); // dp[i] = longest subsequence length ending at index i
        vector<int> parent(n, -1);
        int longestSub = 1;
        int longestSubIdx = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<=i-1; j++){
                if(groups[i] != groups[j] && words[i].length() == words[j].length() && 
                    checkHammingDist(words[i], words[j])){

                        if(dp[j]+1 > dp[i]){
                            dp[i] = dp[j] + 1;
                            parent[i] = j;

                            if(longestSub < dp[i]){
                                longestSub = dp[i];
                                longestSubIdx = i;
                            }
                        }
                    }
            }
        }

        vector<string> ans;
        while(longestSubIdx != -1){
            ans.push_back(words[longestSubIdx]);
            longestSubIdx = parent[longestSubIdx];
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};