class Solution {
public:
    static bool myFunction(string& word1, string& word2){
        return word1.length() < word2.length();
    }

    bool isPredecessor(string& prevString, string& currString){
        int n = prevString.length();
        int m = currString.length();

        if(n > m || m-n != 1) return false;
        
        int i=0, j=0;

        while(i<n && j<m){
            if(prevString[i] == currString[j]){
                i++, j++;
            }
            else{
                j++;
            }
        }
        return (i == n) ;
    }
    int solve(int i, int prev, vector<string>& words,  vector<vector<int>>& t){
        if(i == words.size()){
            return 0;
        }

        if(t[i][prev + 1] != -1){
            return t[i][prev + 1];
        }

        int take = 0;
        if(prev == -1 || isPredecessor(words[prev], words[i])){
            take = 1 + solve(i+1, i, words, t);
        }

        int notTake = solve(i+1, prev, words, t);

        return t[i][prev + 1] = max(take, notTake);
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(), myFunction);

        vector<vector<int>> t(n, vector<int>(n+1, -1));

        return solve(0, -1, words, t);
    }
};