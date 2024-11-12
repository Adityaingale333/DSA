class Solution {
public:
    vector<int> findNse(vector<int> arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            } 
            if(st.empty()) ans[i] = n;
            else ans[i] = st.top();

            st.push(i);
        }
        return ans;
    }
    vector<int> findPsee(vector<int> arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            } 
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();

            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int area = 0;

        vector<int> nse = findNse(heights);
        vector<int> psee = findPsee(heights);

        for(int i=0; i<n; i++){
            area = max(area, heights[i]*(nse[i]-psee[i]-1));
        }
        return area;
    }
};