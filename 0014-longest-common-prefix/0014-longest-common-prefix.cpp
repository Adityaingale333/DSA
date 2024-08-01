class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = "";

        for(int i=0; i<strs[0].length(); i++){ //loop first string ke length brabar chalega
            char ch = strs[0][i]; // first string ka i character pakad ke baki saare string ke i 
                                  // wale character ko check kro  
            bool match = true;

            for(int j=1; j<n; j++){
                // string ka length first string jitna hona chahiye OR
                // ch match hona chahiye, nahi to false krkr break out.
                if(strs[j].size()<i || ch != strs[j][i]){ 

                    match = false;
                    break;
                }
            }
            if(match == false){
                break;
            }
            else{
                ans.push_back(ch);  // uss ch ko saare stirng me check kr liya agar true to pushback
            }
        }
        return ans;
    }
};