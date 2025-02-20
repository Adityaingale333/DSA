class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int> st;

        // insert all elements in set, so that we can find the missing one
        for(string& num : nums){
            st.insert(stoi(num, 0, 2));
        }

        string ans = "";

        // loop from 0 to n, bcz it contains n elements of n bits, so it means if we check
        // from 0 to n any one from it will be missing
        // ex :- {000, 001, 011} here if we check from 0,1,2,3 we will get ans bcz only 3
        // elements are there
        for(int i=0; i<=n; i++){  
            if(st.find(i) == st.end()){
                ans = bitset<16>(i).to_string();

                return ans.substr(16-n, n);
            }
        }
        return "";
    }
};