class Solution {
public:
    int takeCharacters(string s, int k) {
       int n = s.size();

       int counta = 0;
       int countb = 0;
       int countc = 0;

        for(char &ch:s){
            if(ch == 'a') counta++;
            else if(ch == 'b') countb++;
            else countc++;
        }

        if(counta<k || countb<k || countc<k) return -1;

       int i = 0;
       int j = 0; 
       int notDeletedWindowSize = 0;

       while(j < n){
        if(s[j] == 'a') counta--;
        else if(s[j] == 'b') countb--;
        else countc--;

        while(i<=j && (counta<k || countb<k || countc<k)){
            if(s[i] == 'a') counta++;
            else if(s[i] == 'b') countb++;
            else countc++;

            i++;
        }

        notDeletedWindowSize = max(notDeletedWindowSize, j-i+1);
        j++;
       }
       return n - notDeletedWindowSize;
    }
};