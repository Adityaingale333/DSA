class Solution {
public:
    int M = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power;
        vector<int> ans;

        for(int i=0; i<32; i++){
            if( (n&(1<<i)) != 0 ){
                power.push_back(1<<i);
            }
        }

        for(auto& it : queries){
            int start = it[0];
            int end = it[1];

            long long product = 1;
            for(int i=start; i<=end; i++){
                product = (product * power[i]) % M;
            }

            ans.push_back(product);
        }

        return ans;
    }
};