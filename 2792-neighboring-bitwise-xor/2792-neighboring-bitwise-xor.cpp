class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // original = {a,b,c,d,e}
        // derived = {0,1,0,1,1}
        // derived = {a^b, b^c, c^d, d^e, e^a} 
        // if we xor all elements of derived it should come 0, if original exist bcz every
        // element occurs twice otherwise return false
        int n = derived.size();
        int ans = 0;

        for(int i=0; i<n; i++){
            ans  = ans ^ derived[i];
        }

        return ans==0 ? true : false ;
    }
};