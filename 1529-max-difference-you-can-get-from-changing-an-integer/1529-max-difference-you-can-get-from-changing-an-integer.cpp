class Solution {
public:
    int maxDiff(int num) {
        string str1 = to_string(num);
        string str2 = str1;

        int idx = str1.find_first_not_of('9');
        if(idx != string::npos){ // iska mtlb hame idx mil chuka hai
            char ch = str1[idx];
            replace(str1.begin(), str1.end(), ch, '9');
        }

        for(int i=0; i<str2.size(); i++){
            char ch = str2[i];

            if(i == 0){
                if(ch != '1'){
                    replace(str2.begin(), str2.end(), ch, '1');
                    break;
                }
            }
            else if(ch != '0' && ch != str2[0]){
                replace(str2.begin(), str2.end(), ch, '0');
                break;
            }
        }
        return stoi(str1) - stoi(str2);
    }
};