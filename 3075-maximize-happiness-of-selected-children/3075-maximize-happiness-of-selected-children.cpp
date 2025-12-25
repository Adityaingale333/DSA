class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();

        sort(happiness.begin(), happiness.end(), greater<int>());

        int turn = 0;
        int i = 0;
        long long ans = 0;

        while(turn != k && i < n){
            ans = ans + (happiness[i] - turn > 0 ? happiness[i] - turn : 0);
            turn++, i++;
        }

        return ans;
    }
};