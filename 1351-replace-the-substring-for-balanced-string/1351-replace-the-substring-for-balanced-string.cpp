class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        int i=0, j=0;
        int min_length = n;

        // count frequency of each character
        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }

        // check if string is already balanced
        int target = n/4;
        if(mp['Q']<=target && mp['W']<=target && mp['E']<=target && mp['R']<=target){
            return 0;
        }

        while(j<n){
            mp[s[j]]--;

            // while the string is balanced, shrink the window to get minimum length
            while(mp['Q']<=target && mp['W']<=target && mp['E']<=target && mp['R']<=target){
                min_length = min(min_length, j-i+1);
                mp[s[i]]++;
                i++;
            }

            j++;
        }
        return min_length;
    }
};