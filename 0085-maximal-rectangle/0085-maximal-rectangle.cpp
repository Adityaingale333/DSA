class Solution {
public:
    vector<int> getNSL(vector<int>& height){
        int n = height.size();

        stack<int> st;
        vector<int> NSL(n);

        //  [0 2 1 2 0]    agar 1 se dekh rahe hai to 0 <- <- <- 1, skipping 2
        for(int i=0; i<n; i++){ // to get Next_Smaller_element_to_Left, obv we will iterate from letf, so we can check element on its left
            if(st.empty()){
                NSL[i] = -1; // out of bound wala index, left se chalu kr rahe hai isliye -1
            }
            else{
                while(!st.empty() && height[st.top()] >= height[i]){ // next smaller chahiye, isliye greater aur equal wale hata diye
                    st.pop();
                }
                if(st.empty()){
                    NSL[i] = -1; // vappis empty ho gaya mtlb usse smaller hai hi nahi, isliye out of bound wala index
                }
                else{
                    NSL[i] = st.top();
                }
            }
            
            st.push(i); // element to har baar push karenge, kuyki fir uske baad wale ko check krna hai n, ki vo isse chota hai ya nahi

        }

        return NSL;
    }
    vector<int> getNSR(vector<int>& height){
        int n = height.size();

        stack<int> st;
        vector<int> NSR(n);

        for(int i=n-1; i>=0; i--){ // to get Next_Smaller_element_to_Right, obv we will iterate from right
            if(st.empty()){
                NSR[i] = n; // out of bound wala index, right se chale kr rahe hai isliye n
            }
            else{
                while(!st.empty() && height[st.top()] >= height[i]){ // next smaller chahiye, isliye greater aur equal wale hata diye
                    st.pop();
                }
                if(st.empty()){
                    NSR[i] = n; // vappis empty ho gaya mtlb usse smaller hai hi nahi, isliye out of bound wala index
                }
                else{
                    NSR[i] = st.top();
                }
            }
            
            st.push(i); // element to har baar push karenge, kuyki fir uske pehle wale ko check krna hai n, ki vo isse chota hai ya nahi

        }

        return NSR;
    }
    int solve(vector<int>& height){
        int n = height.size();

        vector<int> NSR = getNSR(height);
        vector<int> NSL = getNSL(height);

        int area = INT_MIN;
        for(int i=0; i<n; i++){
            int a = height[i] * (NSR[i] - NSL[i] - 1);
            area = max(area, a); 
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> height(n, 0);
        int maxArea = INT_MIN;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '0'){
                    height[j] = 0;
                }
                else{
                    height[j] = height[j]+1;
                }
            }
            maxArea = max(maxArea, solve(height));
        }
        return maxArea;
    }
};