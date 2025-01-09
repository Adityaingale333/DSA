class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int i=0, j=0;
        int maxlen = 0;
        int flip_Count = 0;

        char var = 'T';
        while(j<n){
            if(answerKey[j] != var){
                flip_Count++;
            }

            while(flip_Count > k){
                if(answerKey[i] != var){
                    flip_Count--;
                }
                i++;
            }

            maxlen = max(maxlen,j-i+1);
            j++;
        }

        var = 'F';
        i = 0, j = 0;
        flip_Count = 0;
        while(j<n){
            if(answerKey[j] != var){
                flip_Count++;
            }

            while(flip_Count > k){
                if(answerKey[i] != var){
                    flip_Count--;
                }
                i++;
            }

            maxlen = max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
};