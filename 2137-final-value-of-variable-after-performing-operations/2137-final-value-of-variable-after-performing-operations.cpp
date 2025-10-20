class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n = operations.size();

        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<3; j++){
                if(operations[i][j] == '+'){
                    ans++;
                    break;
                }
                else if(operations[i][j] == '-'){
                    ans--;
                    break;
                }
            }
        }

        return ans;
    }
};