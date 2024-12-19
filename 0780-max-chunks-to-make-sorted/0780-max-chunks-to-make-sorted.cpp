class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int Osum = 0;
        int sum = 0;
        int count = 0;

        for(int i=0; i<n; i++){
            Osum += i;
            sum = sum + arr[i];

            if(sum == Osum) count++;
        }
        return count;
    }
};