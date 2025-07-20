class Solution {
public:
    string largestGoodInteger(string num) {

        vector<string> digit = {"999", "888", "777", "666", "555", "444", "333", "222", "111", "000"};

        for(int i=0; i<digit.size(); i++){
            if(num.contains(digit[i])){
                return digit[i];
            }
        }

        return "";
    }
};