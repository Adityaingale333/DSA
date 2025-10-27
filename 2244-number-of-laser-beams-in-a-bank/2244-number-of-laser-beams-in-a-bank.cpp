class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size();
        int n = bank[0].size();

        int ans = 0;
        int prevOnes = 0;

        for(int i=0; i<m; i++){
            int currOnes = 0;
            for(int j=0; j<n; j++){
                if(bank[i][j] == '1'){
                    currOnes++;
                }
            }
            ans = ans + (prevOnes * currOnes);
            if(currOnes != 0) prevOnes = currOnes;
        }

        return ans;
    }
};