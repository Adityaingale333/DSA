class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st;
        st.insert(nums[0]);
        int sum = nums[0];
        bool breakFlag = false;

        for(int i=1; i<n; i++){
            if(nums[i] == nums[i-1] + 1 && breakFlag == false){
                sum += nums[i];
            }
            else{
                breakFlag = true;
            }
            st.insert(nums[i]);
        }

        for(int i=sum; i<=1275; i++){
            if(st.find(i) == st.end()){
                return i;
            }
        }

        return -1;
    }
};