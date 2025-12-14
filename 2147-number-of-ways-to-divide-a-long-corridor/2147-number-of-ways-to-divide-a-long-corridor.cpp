class Solution {
public:
    int M = 1e9 + 7;
    int numberOfWays(string corridor) {
        int n = corridor.size();

        vector<int> idx;

        for(int i=0; i<n; i++){
            if(corridor[i] == 'S'){
                idx.push_back(i);
            }
        }

        if(idx.empty() || idx.size() % 2 != 0){
            return 0;
        }

        long long ans = 1;

        for(int i=1; i<idx.size()-1; i+=2){
            ans = (ans * (idx[i+1] - idx[i])) % M;
        }

        return (int)ans;
    }
};