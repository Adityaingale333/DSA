class Solution {
public:
    bool hasDuplicates(string temp, string s){
        vector<int> freq(26, 0);

        for(int i=0; i<temp.size(); i++){
            freq[temp[i]-'a']++;
            if(freq[temp[i]-'a'] > 1){
                return true;
            }
        }

        for(int i=0; i<s.size(); i++){
            freq[s[i]-'a']++;
            if(freq[s[i]-'a'] > 1){
                return true;
            }
        }

        return false;
    }
    int solve(int i, string temp, vector<string>& arr, unordered_map<string, int>& mp){
        if(i >= arr.size()){
            return temp.length();
        }

        if(mp.find(temp) != mp.end()){
            return mp[temp];
        }

        int include = 0;
        int exclude = 0;
        if(hasDuplicates(temp, arr[i])){
            exclude = solve(i+1, temp, arr, mp);
        }
        else{
            include = solve(i+1, temp + arr[i], arr, mp);
            exclude = solve(i+1, temp, arr, mp);
        }
        return mp[temp] = max(include, exclude);
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        string temp = "";

        unordered_map<string, int> mp; // temp -> uska ans
        return solve(0, temp, arr, mp);
    }
};