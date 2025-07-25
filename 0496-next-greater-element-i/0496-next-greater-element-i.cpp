class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        stack<int> st; // decreasing monotonic stack, iterating from right

        vector<int> NGR(10001, -1);

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top() < nums2[i]){
                st.pop();
            }

            if(st.empty()){
                NGR[nums2[i]] = -1;
            }
            else{
                NGR[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        vector<int> ans(m, 0);

        for(int i=0; i<m; i++){
            ans[i] = NGR[nums1[i]];
        }

        return ans;
    }
};