class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n,0);
        int cumValue = 0;
        int cumValueSum = 0;

        // moves for all left ball to index i
        for(int i=0; i<n; i++){
            ans[i] = cumValueSum;
            cumValue = cumValue + (boxes[i]=='0' ? 0 : 1) ;
            cumValueSum = cumValueSum + cumValue; 
        }

        cumValue = 0;
        cumValueSum = 0;
        // moves for all right ball to index i
        for(int i=n-1; i>=0; i--){
            ans[i] = ans[i] + cumValueSum;
            cumValue = cumValue + (boxes[i]=='0' ? 0 : 1) ;
            cumValueSum = cumValueSum + cumValue; 
        }
        return ans;
    }
};