class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();

        int ans = 0;

        int curr = 0;
        int prev = 0;

        for(int i=0; i<n; i++){
            curr = target[i];

            if(abs(curr) > abs(prev)){
                ans = ans + abs(curr) - abs(prev);
            }

            prev = curr;
        }

        return ans;
    }
};