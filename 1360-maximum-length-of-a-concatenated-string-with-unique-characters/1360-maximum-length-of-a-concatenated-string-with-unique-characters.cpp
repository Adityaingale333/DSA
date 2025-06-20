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
    int solve(int i, string temp, vector<string>& arr){
        if(i >= arr.size()){
            return temp.length();
        }

        int include = 0;
        int exclude = 0;
        if(hasDuplicates(temp, arr[i])){
            exclude = solve(i+1, temp, arr);
        }
        else{
            include = solve(i+1, temp + arr[i], arr);
            exclude = solve(i+1, temp, arr);
        }
        return max(include, exclude);
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        string temp = "";
        return solve(0, temp, arr);
    }
};