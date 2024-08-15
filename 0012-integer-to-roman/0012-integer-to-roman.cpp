class Solution {
public:
    string intToRoman(int num) {
        
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string result = "";
        for(int i=0; i<13; i++){
            if(num == 0) break;

            while(num >= values[i]){
                result = result + sym[i];
                num = num - values[i];
            }

        }
        return result;
    }
};