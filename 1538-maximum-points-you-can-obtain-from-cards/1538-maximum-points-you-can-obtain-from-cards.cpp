class Solution {
public:
    // we need to pick consecutively either from front or back, so we can not just take sum of k largest element
    // what we can do is generate all combinations, sum of front k, then sum of front k-1 + last from back, 
    // then sum of front k-2 +  2 from back, ............ 
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftSum = 0;

        for(int i=0; i<k; i++){
            leftSum = leftSum + cardPoints[i];
        }

        int r = n-1; // for rightsum, iterate from back
        int rightSum = 0;
        int maxSum = leftSum;

        for(int i=k-1; i>=0; i--){
            leftSum = leftSum - cardPoints[i];
            rightSum = rightSum + cardPoints[r];
            r--;

            maxSum = max(maxSum, leftSum + rightSum);
        }

        return maxSum;
    }
};