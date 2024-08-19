class Solution {
public:
    int beauty(vector<int> &map){
        int mf = INT_MIN;
        int lf = INT_MAX;

        for(int i=0; i<26; i++){
            mf = max(mf, map[i]);
            if(map[i] >= 1){
                lf = min(lf, map[i]);
            }
        }
        return mf-lf ;
    }

    int beautySum(string s) {
        int n = s.size();
        int ans = 0;

        for(int i=0; i<n; i++){
            vector<int> map(26, 0);
            for(int j=i; j<n; j++){
                map[s[j] - 'a']++;
                ans = ans + beauty(map);
            }
        }
        return ans;
    }
};