class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for(int i=low; i<=high; i++){
            string s = to_string(i);

            int l = s.length();

            if(l%2 != 0){
                continue;
            }

            int leftSum = 0;
            int rightSum = 0;

            for(int j=0; j<l/2; j++){
                leftSum += s[j] - '0';
            }

            for(int j=l/2; j<l; j++){
                rightSum += s[j] - '0';
            }

            if(leftSum == rightSum){
                count++;
            }
        }
        return count;
    }
};