class Solution {
public:
    /*static bool myFunction(string& word1, string& word2){
        return word1.length() < word2.length();
    }*/
    bool isPredecessor(string& prev, string& curr){
        int n = prev.length();
        int m = curr.length();

        if(n > m || m-n != 1) return false;

        int i=0, j=0;

        while(i<n && j<m){
            if(prev[i] == curr[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return (i == n );
    }
    /*int solve(int i, int prevIdx, vector<string>& words){
        if(i == words.size()){
            return 0;
        }

        int take = 0;
        if(prevIdx == -1 || isPredecessor(words[prevIdx], words[i])){
            take = 1 + solve(i+1, i, words);
        }

        int notTake = solve(i+1, prevIdx, words);

        return max(take, notTake);
    }*/
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(), [](string& word1, string& word2){
            return word1.length() < word2.length();
        } );

        vector<int> t(n, 1);

        int maxLen = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(isPredecessor(words[j], words[i])){
                    if(t[j] + 1 > t[i]){
                        t[i] = t[j] + 1;
                    }
                }
            }
            maxLen = max(maxLen, t[i]);
        }

        return maxLen;
    }
};