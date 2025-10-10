class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();

        vector<int> t(n, 0);

        for(int i=n-1; i>=0; i--){
            t[i] = energy[i];
            if(i + k < n){
                t[i] = t[i] + t[i+k];
            }
        }

        int ans = INT_MIN;
        for(int i=0; i<t.size(); i++){
            ans = max(ans, t[i]);
        }

        return ans; 
    }
};