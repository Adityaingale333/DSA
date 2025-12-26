class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();

        vector<int> leftN(n+1, 0);

        for(int i=1; i<=n; i++){
            leftN[i] = leftN[i-1] + (customers[i-1] == 'N' ? 1 : 0);  
        }

        vector<int> rightY(n+1, 0);

        for(int i=n-1; i>=0; i--){
            rightY[i] = rightY[i+1] + (customers[i] == 'Y' ? 1 : 0);
        } 

        int minPen = INT_MAX;
        int ans = 0;

        for(int i=0; i<=n; i++){
            int pen = leftN[i] + rightY[i];  

            if(pen < minPen){
                minPen = pen;
                ans = i;
            }
        }

        return ans;
    }
};