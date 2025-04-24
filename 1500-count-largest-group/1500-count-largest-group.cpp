class Solution {
public:
    int countLargestGroup(int n) {
        int sumCount[37] = {0}; //// Maximum digit sum for n <= 10000 is 36
        int maxSize = INT_MIN;
        int count = 0;

        for(int i=1; i<=n; i++){
            int sum = 0;
            int x = i;
            while(x > 0){
                sum = sum + x%10 ;
                x = x/10;
            }
            sumCount[sum]++;
            maxSize = max(maxSize, sumCount[sum]);
        } 

        for(int i=1; i<=36; i++){
            if(sumCount[i] == maxSize){
                count++;
            }
        }
        return count;
    }
};