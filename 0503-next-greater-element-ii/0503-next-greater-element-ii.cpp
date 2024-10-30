class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        stack<int> st;

        for(int i=2*n-1; i>=0; i--){
            int index = i%n ;
            while(!st.empty() && st.top()<=nums[index]){
                st.pop();
            }
            if(st.empty()) ans.push_back(-1);
            else ans.push_back(st.top());

            st.push(nums[index]);
        }
        reverse(ans.begin(), ans.end());

        return vector<int>(ans.begin(), ans.begin() + n);
    }
};