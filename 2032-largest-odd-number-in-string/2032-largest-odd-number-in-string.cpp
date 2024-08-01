class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        // find the first odd number from end and return the substr
        for(int i=n-1; i>=0; i--){
            if((num[i]-'0')%2 == 1){
                return num.substr(0, i+1); // parameter(first position, length)
            }
        }
         return "";   
    }
};