class Solution {
public:
    // generate all n pallindromes in base 10, and then check if they are apllindromes in base k as well
    
    bool isPallindrome(string s){
        int n = s.size();
        int i=0; 
        int j=n-1;
        while(i<=j){
            if(s[i] != s[j]){
                return false;
            }
            i++, j--;
        }
        return true;
    }
    string convertToBaseK(long long num, int k){
        if (num == 0) return "0";
        string res = "";
        while (num > 0) {
            res.push_back('0' + (num % k)); // collect in reverse order
            num /= k;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    long long kMirror(int k, int n) {
        long long sum = 0;
        int L = 1; // generate all possible lengths pallindrome

        while(n > 0){
            // to generate L length pallindromes, we will require to generate all L+1/2 numbers so to generate
            // pallindromes from them 
            int half_length = (L+1) / 2; 

            // to get all possible half length numbers we will need to get min and max number of them
            long long min_num = pow(10, half_length-1);
            long long max_num = pow(10, half_length) - 1;

            for(int num=min_num; num<=max_num; num++){
                string firstHalf = to_string(num);
                string secondHalf = firstHalf;
                reverse(secondHalf.begin(), secondHalf.end());
                
                string pal = "";
                if(L%2 == 0){ // means we need even length pallindrome
                    pal = firstHalf + secondHalf; // 12 -> rev(12) = 21 -> 12 21
                } 
                else{ // means we need odd length pallindrome
                    pal = firstHalf + secondHalf.substr(1); // 121 -> rev(121) = we do not want first digit(1) 21 -> 121 21
                }

                long long pal_num = stoll(pal);

                string baseK = convertToBaseK(pal_num, k);

                if(isPallindrome(baseK)){
                    sum = sum + pal_num;
                    n--;
                    if(n == 0){
                        break;
                    }
                }
            }
            L++;
        } 
        return sum;
    }
};