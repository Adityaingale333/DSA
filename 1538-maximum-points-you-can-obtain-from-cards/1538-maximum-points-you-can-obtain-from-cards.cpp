class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lsum = 0;
        int r=n-1;

        for(int i=0; i<k; i++){
            lsum = lsum + cardPoints[i]; 
        }

        int maxsum = lsum;
        int rsum = 0;

        for(int i=k-1; i>=0; i--){
            lsum = lsum - cardPoints[i];
            rsum = rsum + cardPoints[r];
            r--;
            maxsum = max(maxsum, lsum+rsum);
        }
        return maxsum;
    }
};