class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();

        int count1 = 0;
        int ans = 0;
        for(int i=0; i<n-1; i++){
            if(s[i] == '1'){
                count1++;
                if(s[i+1] == '0'){
                    ans = ans + count1;
                }
            }
        }

        return ans;
    }
};