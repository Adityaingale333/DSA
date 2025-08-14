class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length();

        string ans = "";
        
        for(int i=0; i<n-2; i++){
            if(num[i] == num[i+1] && num[i] == num[i+2]){
                string curr = num.substr(i, 3);
                if(curr > ans){
                    ans = curr;
                }
            }
        }

        return ans;
    }
};