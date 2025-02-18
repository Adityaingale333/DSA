class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> rowMap;
        
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        for(char c : row1){
            rowMap[c] = 1;
            rowMap[toupper(c)] = 1;
        }

        for(char c : row2){
            rowMap[c] = 2;
            rowMap[toupper(c)] = 2;
        }

        for(char c : row3){
            rowMap[c] = 3;
            rowMap[toupper(c)] = 3;
        }

        vector<string> ans;

        for(auto& word : words){
            int row = rowMap[word[0]];
            bool isValid = true;
            for(auto& ch : word){
                if(rowMap[ch] != row){
                    isValid = false;
                    break;
                }
            }
            if(isValid){
                ans.push_back(word);
            }
        }
        return ans;
    }
};