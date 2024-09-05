class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean * (n+m);
        vector<int> result(n);

        for(int i=0; i<m; i++){
            sum = sum - rolls[i];
        }

        if(sum<n || sum>6*n){
            return {};
        }

        int avg = sum/n;
        int rem = sum%n;

        for(int i=0; i<n; i++){
            result[i] = avg;
            if(rem > 0){
                result[i]++;
                rem--;
            }
        }
        return result;
    }
};