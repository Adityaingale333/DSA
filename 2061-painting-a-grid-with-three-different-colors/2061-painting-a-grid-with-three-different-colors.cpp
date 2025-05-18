class Solution {
public:
    int M = 1e9+7;
    vector<vector<int>> t;

    // Function to generate all valid colorings of a single column
    // No two adjacent cells in a column can have the same color
    void generateStates(string temp, char prevChar, int l, int m, vector<string>& columnStates){
        if(l == m){
            columnStates.push_back(temp);
            return;
        }

        for(char ch : {'R', 'G', 'B'}){
            if(ch == prevChar){
                continue;
            }
            generateStates(temp+ch, ch, l+1, m, columnStates);
        }
    }

    // Recursive function to count the number of ways to color remaining columns
    // while ensuring adjacent columns have no same color in the same row
    int solve(int remainCol, int prevStateIdx, int m, vector<string>& columnStates){
        if(remainCol == 0){
            return 1;
        }

        if(t[remainCol][prevStateIdx] != -1){
            return t[remainCol][prevStateIdx];
        }

        int ways = 0;
        string prevState = columnStates[prevStateIdx];

        // Try all valid next column colorings
        for(int i=0; i<columnStates.size(); i++){
            if(prevStateIdx == i) continue;
            string tryState = columnStates[i];
            bool valid = true;
            // Check if no row in this column has same color as previous column
            for(int j=0; j<m; j++){
                if(prevState[j] == tryState[j]){
                    valid = false;
                    break;
                }
            }
            if(valid){
                ways = (ways + solve(remainCol-1, i, m, columnStates)) % M;
            }
        }
        return t[remainCol][prevStateIdx] = ways;
    }

    int colorTheGrid(int m, int n) {
        vector<string> columnStates;
        generateStates("", '#', 0, m, columnStates); 

        int totalStates = columnStates.size();
        t = vector<vector<int>>(n+1, vector<int>(totalStates+1, -1));

        int result = 0;
        for(int i=0; i<columnStates.size(); i++){
            result = (result + solve(n-1, i, m, columnStates)) % M;
        }
        return result;
    }
};