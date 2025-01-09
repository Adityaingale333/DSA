class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int i=0, j=0;
        int maxlen = 0;
        int T_count = 0;
        int F_count = 0;

        while(j<n){
            if(answerKey[j] == 'T'){
                T_count++;
            }
            else{
                F_count++;
            }

            while(min(T_count, F_count) > k){
                if(answerKey[i]=='T'){
                    T_count--;
                }
                else{
                    F_count--;
                }
                i++;
            }

            maxlen = max(maxlen, j-i+1);
            j++;
        }
        return maxlen;
    }
};