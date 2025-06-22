class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        vector<string> ans;

        for(int i=0; i<n; i+=k){
            string temp = s.substr(i, k); // even if we do not have k char for the last substr, it will return
                                        // substr with remainiing characters upto end of the string 
            if(temp.length() < k){
                temp.append(k-temp.length(), fill);// k-temp.length = 3-1 -> 2 fill char needed
            }
            ans.push_back(temp);
        }
        return ans;
    }
};