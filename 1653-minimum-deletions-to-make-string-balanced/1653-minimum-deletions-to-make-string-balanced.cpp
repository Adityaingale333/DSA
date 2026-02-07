class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();

        int ans = 0;
        int countB = 0;
        
        for(int i=0; i<n; i++){
            if(s[i] == 'b'){
                countB++;
            }
            else{
                ans = min(ans+1, countB);
            }
        }

        return ans;
    }
};