class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        stack<int> st;
        int area = 0;
        int element = 0;
        int nse = 0;
        int pse = 0;

        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                element = st.top();
                st.pop();
                nse = i;
                pse = st.empty()?-1:st.top();
                area = max(area, heights[element]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            nse = n;
            element = st.top();
            st.pop();
            pse = st.empty()?-1:st.top();
            area = max(area, heights[element]*(nse-pse-1));
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> heights(m,0);
        int area = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == '1'){
                    heights[j] = heights[j]+1;
                }
                else heights[j] = 0;
            }
            area = max(area, largestRectangleArea(heights));
        }
        return area;
    }
};