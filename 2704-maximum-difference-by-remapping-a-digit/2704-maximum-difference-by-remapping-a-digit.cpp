class Solution {
public:
    int minMaxDifference(int num) {
        string numStr = to_string(num);
        int n = numStr.size();

        char digit_to_replace;
        for(int i=0; i<n; i++){
            if(numStr[i] != '9'){
                digit_to_replace = numStr[i];
                break;
            }
        }

        // this will replace all the digit we want to remap to 9
        string maxNum = numStr; 
        for(int i=0; i<n; i++){
            if(numStr[i] == digit_to_replace){
                maxNum[i] = '9';
            }
        }

        // the digit to remmap to 0, for getting smallest number will be num[0], bcz input does not have leading zero
        string minNum = numStr;
        char replace = numStr[0];
        for(int i=0; i<n; i++){
            if(numStr[i] == replace){
                minNum[i] = '0';
            }
        }

        return stoi(maxNum) - stoi(minNum);
    }
};