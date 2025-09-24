class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0){
            return "0"; 
        }

        string ans;
        if((long long)numerator * (long long)denominator < 0){
            ans += '-';
        }

        long long absNumerator = labs(numerator);
        long long absDenominator = labs(denominator);

        long long integerDiv = absNumerator / absDenominator;

        ans += to_string(integerDiv);

        long long remainder = absNumerator % absDenominator;
        if(remainder == 0){
            return ans;
        }

        ans += '.';

        unordered_map<int, int> mp; 

        while(remainder != 0){
            if(mp.find(remainder) != mp.end()){
                ans.insert(mp[remainder], "(");
                ans += ')';
                break;
            }

            mp[remainder] = ans.length();
            remainder = remainder * 10;
            int digit = remainder / absDenominator;
            ans += to_string(digit);
            remainder = remainder % absDenominator;
        }

        return ans;
    }
};