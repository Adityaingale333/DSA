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
        vector<vector<int>> prefixSum(n,vector<int>(m));
        for(int j=0; j<m; j++){
            int sum = 0;
            for(int i=0; i<n; i++){
                sum = sum + matrix[i][j] - '0' ;
                if(matrix[i][j] - '0' == 0) sum = 0;
                prefixSum[i][j] = sum;
            }
        }
        int area = 0;
        for(int i=0; i<n; i++){
            area = max(area, largestRectangleArea(prefixSum[i]));
        }
        return area;
    }
};