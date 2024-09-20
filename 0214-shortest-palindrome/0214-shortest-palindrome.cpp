class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        for(int i=0; i<s.length(); i++){
            // memcmp memory me compare krta hai, so no memory limit exceede
            // memcmp agar equal aaya to 0 return krta hai, isliye ! lagaya matlab 1 ho jayega 
            if(!memcmp(s.c_str(), rev.c_str()+i, s.length()-i)){
                return rev.substr(0,i) + s;
            }
        }
        return rev + s; 
    }
};