class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int new_k = k%n;
        stack<int> st;

        for(int i=n - new_k - 1; i>=0; i--){
            st.push(nums[i]);
        }
        for(int i=n-1; i>=n - new_k; i--){
            st.push(nums[i]);
        }
        for(int i=0; i<n; i++){
            nums[i] = st.top();
            st.pop();
        }
    }
};