class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int count = 0;
        int max_count = INT_MIN;
        int i=0, j=0;
        while(j<n){
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u'){
                count++;
            }
            while(j-i+1 > k){
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                    count--;
                }
                i++;
            }
            max_count = max(max_count, count);
            j++;
        }
        return max_count;
    }
};