class Solution {
public:
    const int M = 1e9 + 7;
    int numSub(string s) {
        int n = s.length();

        long long ans = 0;
        long long count = 0;

        for(auto& ch : s){
            if(ch == '1'){
                count++;
                ans = (ans + count) % M;
            }
            else{
                count = 0;
            }
        }

        return ans;
    }
};