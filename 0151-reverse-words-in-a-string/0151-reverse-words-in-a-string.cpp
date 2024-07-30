class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int n = s.size();
        int i = 0;
        int l = 0, r = 0; // words ko reverse krne ke liye

        while(i<n){
            while(i<n && s[i]!=' '){ // jab tak space nahi milta i aur r ko aage badhao
                s[r] = s[i];
                i++;
                r++;
            }
            if(l<r){ // jaise hi space mila uss word ko reverse krdo
                reverse(s.begin()+l, s.begin()+r); // begin + l, kyuki l bhi move krega  
                s[r] = ' '; // r ko ek space dedo
                r++; // r ko aage badhao
                l = r; // l aur r saath me aajayenge, new word ke liye
            }
            i++;
        }
        s = s.substr(0, r-1);
        return s;
    }
};