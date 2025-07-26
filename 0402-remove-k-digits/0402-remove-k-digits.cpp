class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();

        if(k >= n) return "0";

        string ans = "";

        for(int i=0; i<n; i++){
            while(!ans.empty() && ans.back() > num[i] && k > 0){
                ans.pop_back();
                k--;
            }

            if(!ans.empty() || num[i] != '0'){
                ans.push_back(num[i]);
            }
            
        }

        while(k > 0 && !ans.empty()){
            ans.pop_back();
            k--;
        }

        return ans == "" ? "0" : ans;
    }
};