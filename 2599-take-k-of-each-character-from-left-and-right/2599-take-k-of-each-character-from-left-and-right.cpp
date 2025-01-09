class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();

        int counta = 0;
        int countb = 0;
        int countc = 0;

        for(int i=0; i<n; i++){
            if(s[i]=='a') counta++;
            else if(s[i]=='b') countb++;
            else countc++;
        }

        if(counta<k || countb<k || countc<k) return -1;

        int i=0, j=0;
        int windowNotDelete = 0;

        while(j<n){
            if(s[j]=='a') counta--;
            else if(s[j]=='b') countb--;
            else countc--;

            while(i<=j && (counta < k || countb < k || countc < k) ){  // a,b,c inside window should be less than k
                if(s[i]=='a') counta++;
                else if(s[i]=='b') countb++;
                else countc++;

                i++;
            }
            windowNotDelete = max(windowNotDelete, j-i+1);
            j++;
        }
        return n - windowNotDelete;
    }
};