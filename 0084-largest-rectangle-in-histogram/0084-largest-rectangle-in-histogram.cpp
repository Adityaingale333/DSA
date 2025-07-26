class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        stack<int> st; // increasing stack
        vector<int> NSE(n); // iterate from right

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] > heights[i]){
                st.pop();
            }

            if(st.empty()){
                NSE[i] = n;
            }
            else{
                NSE[i] = st.top();
            }

            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        vector<int> PSEE(n);
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(st.empty()){
                PSEE[i] = -1;
            }
            else{
                PSEE[i] = st.top();
            }

            st.push(i);
        }

        int ans = 0;

        for(int i=0; i<n; i++){
            int left = i - PSEE[i];
            int right = NSE[i] - i;

            int breadth = left + right - 1;
            int length = heights[i];

            int area = length * breadth;

            ans = max(ans, area);
        }

        return ans;
    }
};