class Solution {
public:
    int largestArea(vector<int>& height){
        int n = height.size();

        stack<int> st; // increasing stack
        vector<int>  NSE(n);

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && height[st.top()] > height[i]){
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
            while(!st.empty() && height[st.top()] >= height[i]){
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
            int length = height[i];

            int area = length * breadth;

            ans = max(ans, area);
        }

        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int ans = 0;

        vector<int> height(n, 0);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '0'){
                    height[j] = 0;
                }
                else{
                    height[j] = height[j] + 1;
                }
            }
            ans = max(ans, largestArea(height));
        } 

        return ans;
    }
};