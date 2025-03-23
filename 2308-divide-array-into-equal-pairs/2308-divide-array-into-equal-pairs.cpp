class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st;
        for(auto& it : nums){
            if(st.count(it)){
                st.erase(it);
            }
            else{
                st.insert(it);
            }
        }
        return st.empty();
    }
};