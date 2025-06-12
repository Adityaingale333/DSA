class Solution {
public:
    // time complexity = solve{ O(2^n * 1) }, we can check pallindrome in O(1) bcz of dp table
    // O(n*n) for creaing dp table
    // overall O(2^n)
    void solve(int i, vector<string>& currPartition, string& s, vector<vector<string>>& ans, vector<vector<bool>>& t){
        if(i == s.size()){ // i reached s.length() means we succesfully paritioned
            ans.push_back(currPartition);
            return;
        }

        for(int j=i; j<s.length(); j++){
            if(t[i][j] == true){
                currPartition.push_back(s.substr(i, j-i+1));
                solve(j+1, currPartition, s, ans, t);
                currPartition.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();

        // t[i][j] -> states, if the substring from i to j is pallindrome or not
        vector<vector<bool>> t(n, vector<bool>(n, false)); 

        // use this observation to build dp table
        for(int i=0; i<n; i++){
            t[i][i] = true; // substring of length 1 is always pallindrome
        }

        for(int len=2; len<=n; len++){ // we want substring of all lengths from 1 to n
            for(int i=0; i + (len-1)<n; i++){ // we want substring to start from every index of different lengths
                int j = i + (len-1); // from len = j-i+1

                if(len == 2){ // or i can also say if(i+1 == j), means the are adjacent
                    t[i][j] = (s[i] == s[j]); // if both are same then obv they are pallindrome
                }
                else{ // for len > 2 , {len = 3 -> n}
                    t[i][j] = (s[i] == s[j] && t[i+1][j-1]); // if first and last ch are same, then we check for between them
                }
            }
        }
        

        vector<vector<string>> ans;
        vector<string> currPartition;

        solve(0, currPartition, s, ans, t);

        return ans;
    }
};