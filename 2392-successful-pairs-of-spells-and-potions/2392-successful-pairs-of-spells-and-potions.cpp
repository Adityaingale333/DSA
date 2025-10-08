class Solution {
public:
    int bs(long long target, vector<int>& potions){
        int low = 0;
        int high = potions.size()-1;

        int idx = -1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(potions[mid] >= target){
                idx = mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }

        return idx;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();

        sort(potions.begin(), potions.end());

        vector<int> ans(n, 0);

        for(int i=0; i<n; i++){
            long long val = 0;
            if(success % spells[i] == 0){
                val = success / spells[i];
            }
            else{
                val = (success / spells[i]) + 1;
            } 

            int j = bs(val, potions);
            if(j != -1) ans[i] = m-j;
        }

        return ans;
    }
};