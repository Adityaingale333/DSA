class Solution {
public:
    int maximum69Number (int num) {
        int temp = num;
        int i=0;
        int idx = 0;
        bool found6 = false;
        while(temp != 0){
            int rem = temp % 10;
            if(rem == 6){
                idx = i;
                found6 = true;
            }
            i++;
            temp = temp/10;
        }

        return (found6 == true) ? num + (3 * pow(10, idx)) : num;
    }
};