class Solution {
public:
    bool check(vector<int>& nums, int start){
        unordered_set<int> st;
        for(int i=start; i<nums.size(); i++){
            if(st.count(nums[i])){
                return false;
            }
            st.insert(nums[i]);
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int op = 0;

        for(int i=0; i<n; i+=3){
            if(check(nums, i) == true){
                return op;
            }
            op++;
        }
        return op;
    }
};