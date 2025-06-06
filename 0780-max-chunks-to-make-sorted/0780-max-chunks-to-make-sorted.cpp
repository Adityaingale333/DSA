class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
      int n = arr.size();
      int count = 0;
      int maxTillNow = -1;  

      for(int i=0; i<n; i++){
        maxTillNow = max(maxTillNow, arr[i]);

        if(maxTillNow == i) count++;
      }  
      return count;
    }
};